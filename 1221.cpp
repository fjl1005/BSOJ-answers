#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)

const ll maxn = 100005; 
ll n;
ll sum[maxn*4],lmax[maxn*4],rmax[maxn*4],mmax[maxn*4],lmin[maxn*4],rmin[maxn*4],mmin[maxn*4];
void pushup(ll v){
	sum[v]=sum[lc(v)]+sum[rc(v)];
	lmax[v]=max(lmax[lc(v)],sum[lc(v)]+lmax[rc(v)]);
	rmax[v]=max(rmax[rc(v)],sum[rc(v)]+rmax[lc(v)]);
	mmax[v]=max(rmax[lc(v)]+lmax[rc(v)],max(mmax[lc(v)],mmax[rc(v)]));
	lmin[v]=min(lmin[lc(v)],sum[lc(v)]+lmin[rc(v)]);
	rmin[v]=min(rmin[rc(v)],sum[rc(v)]+rmin[lc(v)]);
	mmin[v]=min(rmin[lc(v)]+lmin[rc(v)],min(mmin[lc(v)],mmin[rc(v)]));
}
void update(ll v,ll l,ll r,ll ux,ll add){
	if(l==r){sum[v]=lmax[v]=rmax[v]=mmax[v]=lmin[v]=rmin[v]=mmin[v]=add;return;}
	ll mid=(l+r)>>1;
	if(ux<=mid)update(lc(v),l,mid,ux,add);
	else update(rc(v),mid+1,r,ux,add);
	pushup(v);
}
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){ll t;scanf("%lld",&t);update(1,1,n,i,t);}
	ll m;scanf("%lld",&m);
	while(m--){
		ll a,b;scanf("%lld%lld",&a,&b);
		update(1,1,n,a,b);
		ll ans=0;
		ans=sum[1]-mmin[1];
		if(mmax[1]!=sum[1])ans=max(ans,mmax[1]);
		printf("%lld\n",ans);
	}
	return 0;
}
