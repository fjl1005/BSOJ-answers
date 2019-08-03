#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll maxn=1000005;
ll tree[maxn];
ll n,m;
inline ll lowbit(ll x){return x&-x;}
ll query(ll x){ll ans=0;for(ll i=x;i>0;i-=lowbit(i))ans+=tree[i];return ans;}
ll update(ll x,ll d){for(ll i=x;i<=maxn;i+=lowbit(i))tree[i]+=d;}

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){ll t;scanf("%lld",&t);update(i,t);}
	while(m--){
		ll k,x,y;scanf("%lld%lld%lld",&k,&x,&y);
		if(k==1)update(x,y);else printf("%lld\n",query(y)-query(x-1));
	}
	return 0;
}