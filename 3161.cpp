#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll maxn=1000005;
const ll maxm=1000005;
ll u[2*maxm],v[2*maxm];
ll first[maxn],next[2*maxm];
ll tot=0;
void addedge(ll a,ll b){
	tot++;u[tot]=a,v[tot]=b;
	next[tot]=first[a];first[a]=tot;
}
ll L[maxn],R[maxn];
ll step=0;
bool vis[maxn];
void dfs(ll x){
	L[x]=++step;vis[x]=1;
	for(ll i=first[x];i;i=next[i])if(!vis[v[i]])dfs(v[i]);
	R[x]=++step;
}

ll tree[maxn];
inline ll lowbit(ll x){return x&(-x);}
ll query(ll x){ll sum=0;for(ll i=x;i>0;i-=lowbit(i))sum+=tree[i];return sum;}
void update(ll x,ll d){for(ll i=x;i<=maxn;i+=lowbit(i))tree[i]+=d;}
ll n,m,f[maxn];
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<n;i++){
		ll a,b;scanf("%lld%lld",&a,&b);
		addedge(a,b),addedge(b,a);
	}
	dfs(1);
	for(ll i=1;i<=n;i++)update(L[i],1),f[i]=-1;
	scanf("%lld",&m);
	for(ll i=1;i<=m;i++){
		char ch=getchar();while(ch!='C'&&ch!='Q')ch=getchar();
		if(ch=='C'){ll x;scanf("%lld",&x);update(L[x],f[x]);f[x]=-f[x];}
		else {ll x;scanf("%lld",&x);printf("%lld\n",query(R[x])-query(L[x]-1));}
	}
	return 0;
}