#include<cstdio>

#define ll long long
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define fa(x) (x>>1)

inline ll Max(ll a,ll b){return a>b?a:b;}

inline ll read(){
	char ch=getchar();ll f=1,s=0;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return f*s;
}

const ll maxn = 10005;
const ll maxm = 400005;
const ll maxc = 100005;
ll n;
ll ans[maxc];
ll cl[maxn*4];
struct p{
	ll lx,ly,rx,ry,color;
}g[maxn];
ll px[maxm];
bool book[maxn];

void update(ll v,ll l,ll r,ll ul,ll ur,ll set){
	if(cl[v]>0)return;
	if(ul<=l&&r<=ur&&cl[v]!=-1){cl[v]=set;return;}
	ll mid=(l+r)>>1;
	if(ul<=mid)update(lc(v),l,mid,ul,ur,set);
	if(ur>mid)update(rc(v),mid+1,r,ul,ur,set);
	cl[v]=-1;
}

void query(ll v,ll l,ll r,ll d){
	if(cl[v]>0){ans[cl[v]]+=(r-l+1)*d;cl[v]=0;return;}
	if(cl[v]){
		ll mid=(l+r)>>1;
		if(cl[lc(v)])query(lc(v),l,mid,d);
		if(cl[rc(v)])query(rc(v),mid+1,r,d);
		cl[v]=0;
	}
}

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ll a=read(),b=read();n=read();ll cm=0;
	for(ll i=1;i<=n;i++){
		g[i].lx=read(),g[i].ly=read(),g[i].rx=read(),g[i].ry=read(),g[i].color=read();cm=Max(cm,g[i].color);
		book[g[i].lx]=book[g[i].rx]=1;
	}
	for(ll i=0;i<=maxm;i++)if(book[i])px[++px[0]]=i;
	for(ll i=1;i<px[0];i++){
		for(ll j=n;j>=1;j--)if(g[j].lx<=px[i]&&px[i]<g[j].rx)update(1,0,b-1,g[j].ly,g[j].ry-1,g[j].color);
		query(1,0,b-1,px[i+1]-px[i]);
	}
	ans[1]=a*b;
	for(ll i=2;i<=cm;i++)ans[1]-=ans[i];
	for(ll i=1;i<=cm;i++)if(ans[i])printf("%lld %lld\n",i,ans[i]);
	return 0;
}
/*
20 20 3
2 2 18 18 2
0 8 19 19 3
8 0 10 19 4

*/