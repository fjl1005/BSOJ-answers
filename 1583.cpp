#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 100001;
ll trie[maxn*31][2];
ll n,ans=0,cnt=0,dis[maxn];
ll v[maxn*2],w[maxn*2],first[maxn],next[maxn*2],tot=0;
inline void addedge(ll a,ll b,ll c){
	tot++;v[tot]=b,w[tot]=c;next[tot]=first[a];first[a]=tot;
}
void dfs(ll x,ll fa){
	for(ll i=first[x];i;i=next[i])
		if(v[i]!=fa){
			dis[v[i]]=dis[x]^w[i];
			dfs(v[i],x);
		}
}
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<n;i++){
		ll a,b,c;scanf("%lld%lld%lld",&a,&b,&c);a++,b++;
		addedge(a,b,c);addedge(b,a,c);
	}
	dfs(1,0);
	for(ll i=1;i<=n;i++){
		ll t;t=dis[i];
		ll cur=0,la=0;
		for(ll j=31;j>=0;j--){
			ll to=((t>>j)&1)^1;
			if(!trie[cur][to])to^=1;
			la<<=1;la+=to;cur=trie[cur][to];
		}
		cur=0;
		for(ll j=31;j>=0;j--){
			ll to=(t>>j)&1;
			if(!trie[cur][to])trie[cur][to]=++cnt;
			cur=trie[cur][to];
		}
		ans=max(ans,t^la);
	}
	printf("%lld",ans);
	return 0;
}
