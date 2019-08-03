#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll maxn=50005;
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
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]),a[i]++;
	for(ll i=1;i<=n;i++){
		b[i]=query(a[i]-1);
		update(a[i],1);	
	}memset(tree,0,sizeof tree);
	for(ll i=n;i>=1;i--){
		c[i]=query(a[i]-1);
		update(a[i],1);	
	}
	for(ll i=1;i<=n;i++)ans+=b[i]*c[i],lq+=(i-1-b[i])*(n-i-c[i]);
	printf("%lld",ans);
	return 0;
}