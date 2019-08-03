#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long

const ll maxn=500005;
ll tree[maxn];
ll n,m,k;
inline ll Max(ll a,ll b){return a>b?a:b;}
ll a[maxn],b[maxn];
inline ll lowbit(ll x){return x&(-x);}
ll query(ll x){ll sum=0;for(ll i=x;i>0;i-=lowbit(i))sum+=tree[i];return sum;}
void update(ll x,ll d){for(ll i=x;i<=maxn;i+=lowbit(i))tree[i]+=d;}

ll ans=0;
struct edge{
	ll l,r;
	bool operator < (const edge &a)const{return l!=a.l?l<a.l:r<a.r;}
}e[maxn];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ll t;scanf("%lld",&t);ll tp=0;
	while(t--){
		memset(tree,0,sizeof tree);ans=0;
		scanf("%lld%lld%lld",&n,&m,&k);
		for(ll i=1;i<=k;i++)scanf("%lld%lld",&e[i].l,&e[i].r);
		sort(e+1,e+k+1);
		for(ll i=1;i<=k;i++)a[i]=e[i].r,b[i]=a[i];
		sort(b+1,b+k+1);
		ll len=unique(b+1,b+k+1)-b-1;
		for(ll i=1;i<=k;i++)a[i]=upper_bound(b+1,b+len+1,a[i])-b-1;
		ll maxx=0,la=0;
		for(ll i=1;i<=k;i++){
			la=query(maxx)-query(a[i]);
			ans+=la;update(a[i],1);if(a[i]>maxx)maxx=a[i];	
		}
		tp++;printf("Test case %lld: ",tp);
		printf("%lld\n",ans);
	}
	return 0;
}