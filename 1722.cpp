#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 3200005;
ll n,m,decnt=0;
ll L[maxn],R[maxn],size[maxn],root[maxn];
void build(ll &cur,ll l,ll r){
	cur=++decnt;ll mid=(l+r)>>1;
	if(l<r)build(L[cur],l,mid),build(R[cur],mid+1,r);
}
void update(ll &cur,ll pre,ll l,ll r,ll add){
	cur=++decnt;ll mid=(l+r)>>1;L[cur]=L[pre],R[cur]=R[pre];size[cur]=size[pre]+1;
	if(l<r){
		if(add<=mid)update(L[cur],L[pre],l,mid,add);
		else update(R[cur],R[pre],mid+1,r,add);
	}
}
ll query(ll cur,ll pre,ll l,ll r,ll k){
	if(l==r)return l;
	ll p=size[L[cur]]-size[L[pre]];ll mid=(l+r)>>1;
	if(k<=p)return query(L[cur],L[pre],l,mid,k);
	else return query(R[cur],R[pre],mid+1,r,k-p);
}
ll a[maxn],b[maxn];
void init(){
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);b[0]=unique(b+1,b+n+1)-b-1;
	for(ll i=1;i<=n;i++)a[i]=lower_bound(b+1,b+b[0]+1,a[i])-b;
}
void work(){
	build(root[0],1,b[0]);
	for(ll i=1;i<=n;i++)update(root[i],root[i-1],1,b[0],a[i]);
	for(ll i=1;i<=m;i++){ll l,r,k;scanf("%lld%lld%lld",&l,&r,&k);printf("%lld\n",b[query(root[r],root[l-1],1,b[0],k)]);}
}
int main(){
	init();
	work(); 
	return 0;
}
/*
4 4
1 3 2 4 
1 4 4
1 4 4
1 4 1
1 4 4

4
4
1
4
*/