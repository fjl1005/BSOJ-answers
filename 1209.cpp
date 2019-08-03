#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define lc(x) (x<<1)
#define rc(x) ((x<<1)|1)
#define fa(x) (x>>1)

inline ll Max(ll a,ll b){return a>b?a:b;}

const ll maxn=500005;

ll height[maxn];
struct p{
	ll l,r,h;
}a[maxn];
ll b[maxn];
ll n;
void update(ll v,ll l,ll r,ll ul,ll ur,ll hi){
	if(ul<=l&&r<=ur){height[v]=Max(height[v],hi);return;}
	ll mid=(l+r)>>1;
	if(ul<=mid)update(lc(v),l,mid,ul,ur,hi);
	if(ur>mid)update(rc(v),mid+1,r,ul,ur,hi);
}
ll ans=0,tmp=0;
void query(ll v,ll pos,ll l,ll r){
	tmp=max(tmp,height[v]);
	if(l==r)return ;
	ll mid=(l+r)>>1;
	if(pos<=mid)query(lc(v),pos,l,mid);
	else query(rc(v),pos,mid+1,r);
}

int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){scanf("%lld%lld%lld",&a[i].l,&a[i].r,&a[i].h);b[i]=a[i].l,b[n+i]=a[i].r;}
	sort(b+1,b+2*n+1);
	ll len=unique(b+1,b+2*n+1)-b-1;
	//for(int i=1;i<=len;i++)cout<<i<<" "<<b[i]<<endl;
	for(ll i=1;i<=n;i++){
		a[i].l=lower_bound(b+1,b+len+1,a[i].l)-b;
		a[i].r=lower_bound(b+1,b+len+1,a[i].r)-b;
		update(1,1,4*n,a[i].l,a[i].r-1,a[i].h);
		
		ans=0;
	//	if(i==2)
	//	query(1,1,2*n),cout<<ans<<endl;
	//	system("pause");
	}
	for(int i=1;i<len;i++){
		tmp=0;query(1,i,1,4*n);
		ans+=tmp*(long long)(b[i+1]-b[i]);
	}
	printf("%lld",ans);
	return 0;
}
/*
5
1 2 7
1 6 2
11 14 8
5 15 5
4 8 6
*/
