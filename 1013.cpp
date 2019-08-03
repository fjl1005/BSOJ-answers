#include<cstdio>
#include<vector>
using namespace std;
#define ll long long

const ll inf=1<<30;

inline ll min(ll a,ll b){
	return a<b?a:b;
}

const ll maxn=10010;

ll n;
ll dp[maxn][3];// 0 self choose 1 father choose 2 child choose
bool vis[maxn];

struct edges{
	ll u[maxn*2],v[maxn*2];
	ll first[maxn],next[maxn*2];
	ll tot=0;
	void addedge(ll a,ll b){
		tot++;u[tot]=a,v[tot]=b;
		next[tot]=first[a];
		first[a]=tot;
	}
}e;

void dfs(ll x,ll fa){
	vis[x]=1;
	dp[x][0]=1;
	dp[x][1]=0;
	dp[x][2]=inf;
	ll d=inf;
	for(ll i=e.first[x];i;i=e.next[i]){
		ll v=e.v[i];
		if(!vis[v]){
			dfs(v,x);
			dp[x][0]+=min(dp[v][2],min(dp[v][0],dp[v][1]));
			dp[x][1]+=min(dp[v][0],dp[v][2]);
		}
	}
	for(ll i=e.first[x];i;i=e.next[i]){
		ll v=e.v[i];
		if(fa==v)continue;
		dp[x][2]=min(dp[x][2],dp[x][1]+dp[v][0]-min(dp[v][0],dp[v][2]));
	}
}

int main(){
	ll n;scanf("%lld",&n);
	for(ll i=1;i<n;i++){
		ll a,b;scanf("%lld%lld",&a,&b);
		e.addedge(a,b),e.addedge(b,a);
	}
	dfs(1,-1);
	printf("%lld",min(dp[1][0],dp[1][2]));
	return 0;
}