#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long

const ll maxn=100005;
ll tree[maxn];
ll n;

inline ll lowbit(ll x){return x&-x;}
ll query(ll x){ll ans=0;for(ll i=x;i>0;i-=lowbit(i))ans+=tree[i];return ans;}
ll update(ll x,ll d){for(ll i=x;i<=maxn;i+=lowbit(i))tree[i]+=d;}

struct point{
	ll x,y,id,ans;
	bool operator < (const point &a)const{return y!=a.y?y>a.y:x<a.x;}
}p[maxn];
ll cmp(const point &a,const point &b){return a.id<b.id;}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	while(scanf("%lld",&n)!=EOF){
		if(n==0)break;
		for(ll i=1;i<=n;i++)scanf("%lld%lld",&p[i].x,&p[i].y),++p[i].x,++p[i].y,p[i].id=i;
		sort(p+1,p+n+1);
		for(ll i=1;i<=n;i++){if(p[i].x==p[i-1].x&&p[i].y==p[i-1].y)p[i].ans=p[i-1].ans;else p[i].ans=query(p[i].x);update(p[i].x,1);}
		sort(p+1,p+n+1,cmp);
		for(ll i=1;i<=n;i++)printf("%lld ",p[i].ans);puts("");
		memset(tree, 0 ,sizeof tree);
	}
	return 0;
}