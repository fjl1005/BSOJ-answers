#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll maxn=200005;
ll tree[maxn];
ll n;
inline ll Max(ll a,ll b){return a>b?a:b;}

inline ll lowbit(ll x){return x&(-x);}
ll query(ll x){ll sum=0;for(ll i=x;i>0;i-=lowbit(i))sum+=tree[i];return sum;}
void update(ll x,ll d){for(ll i=x;i<=maxn;i+=lowbit(i))tree[i]+=d;}

ll a[maxn],b[maxn],c[maxn];
ll ans=0,lq=0;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(ll i=1;i<=n;i++){
		b[i]=query(a[i]);update(a[i],1);	
	}
	ll maxx=0;memset(tree,0,sizeof tree);
	for(ll i=n;i>=1;i--){
		c[i]=query(maxx)-query(a[i]);
		update(a[i],1);if(a[i]>maxx)maxx=a[i];	
	}
	for(ll i=1;i<=n;i++)ans+=c[i]*(c[i]-1)/2-b[i]*c[i];
//	for(ll i=1;i<=n;i++)printf("%lld %lld\n",b[i],c[i]);
	printf("%lld",ans);
	return 0;
}
/*
*/
