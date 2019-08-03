#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long

const ll maxn=100005;
ll tree[maxn];
ll n;
ll b[maxn];

inline ll lowbit(ll x){return x&-x;}
ll query(ll x){ll ans=0;for(ll i=x;i>0;i-=lowbit(i))ans+=tree[i];return ans;}
ll update(ll x,ll d){for(ll i=x;i<=n;i+=lowbit(i))tree[i]+=d;}

struct point{
	ll x,y;
	bool operator < (const point &a)const{return x!=a.x?x<a.x:y<a.y;}
}p[maxn];
ll ans[maxn];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld%lld",&p[i].x,&p[i].y),++p[i].x,++p[i].y,b[i]=p[i].y;
	sort(b+1,b+n+1);
	ll len=unique(b+1,b+n+1)-b-1;
	for(ll i=1;i<=n;i++)p[i].y=upper_bound(b+1,b+len+1,p[i].y)-b;
	sort(p+1,p+n+1);
	for(ll i=1;i<=n;i++){ans[query(p[i].y)]++;update(p[i].y,1);}
	for(ll i=0;i<n;i++)printf("%lld\n",ans[i]);
	return 0;
}
