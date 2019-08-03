#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=500005;
const ll inf=1ll<<30;
ll size[maxn],n,minn=inf,core[maxn],t;bool vis[maxn];
ll v[maxn*2],next[maxn*2],first[maxn],tot=0;
void addedge(ll a,ll b){++tot;v[tot]=b;next[tot]=first[a];first[a]=tot;}
void dfs(ll x){
	vis[x]=1,size[x]=1;ll maxx=0;
	for(ll i=first[x];i;i=next[i])
		if(!vis[v[i]]){
			dfs(v[i]);
			maxx=max(maxx,size[v[i]]);
			size[x]+=size[v[i]];
		}
	maxx=max(maxx,n-size[x]);
//	printf("%lld\n",maxx);
	if(minn==maxx)core[++core[0]]=x;
	if(minn>maxx)minn=maxx,core[1]=x,core[0]=1;
}

int main(){
	scanf("%lld",&n);
	for(ll i=1;i<n;i++){
		ll x,y;scanf("%lld%lld",&x,&y);x++,y++;
		addedge(x,y);addedge(y,x);
	}
	dfs(1);
	printf("%lld %lld\n",minn,core[0]);
	for(ll i=1;i<=core[0];i++)printf("%lld ",core[i]-1);
	return 0;
}