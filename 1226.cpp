#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long

const ll maxn=500005;
ll tree[maxn];
ll n;
inline ll Max(ll a,ll b){return a>b?a:b;}

inline ll lowbit(ll x){return x&(-x);}
ll query(ll x){ll sum=0;for(ll i=x;i>0;i-=lowbit(i))sum+=tree[i];return sum;}
void update(ll x,ll d){for(ll i=x;i<=maxn;i+=lowbit(i))tree[i]+=d;}

ll a[maxn],b[maxn];
ll ans=0;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	while(scanf("%lld",&n)!=EOF){
		if(n==0)break;
		for(ll i=1;i<=n;i++)scanf("%lld",&a[i]),b[i]=a[i];
		sort(b+1,b+n+1);
		ll len=unique(b+1,b+n+1)-b-1;
		for(ll i=1;i<=n;i++)a[i]=upper_bound(b+1,b+len+1,a[i])-b-1;
		ll maxx=0,la=0;
		for(ll i=1;i<=n;i++){
			la=query(maxx)-query(a[i]);
			ans+=la;update(a[i],1);if(a[i]>maxx)maxx=a[i];	
		}
		printf("%lld\n",ans);
		memset(tree,0,sizeof tree);
		ans=0;
	}
	return 0;
}
