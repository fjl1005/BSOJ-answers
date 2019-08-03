#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll maxn=1000005;
ll tree[maxn],sum[maxn];
ll n,m;
inline ll lowbit(ll x){return x&-x;}
ll query(ll x){ll ans=0;for(ll i=x;i>0;i-=lowbit(i))ans+=tree[i];return ans;}
ll update(ll x,ll d){for(ll i=x;i<=maxn;i+=lowbit(i))tree[i]+=d;}

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){ll t;scanf("%lld",&t);sum[i]=t;}
	while(m--){
		ll k;scanf("%lld",&k);
		if(k==1){ll l,r,val;scanf("%lld%lld%lld",&l,&r,&val);update(l,val),update(r+1,-val);}
		else{ll x;scanf("%lld",&x);printf("%lld\n",sum[x]+query(x));}
	}
	return 0;
}