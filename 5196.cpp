#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long

const ll inf=0x3f3f3f3f3f3f3f3f;

inline ll Min(ll a,ll b){

	return a<b?a:b;

}

const ll maxn=25;

ll dis[maxn+5];

bool vis[maxn+5];
ll n,m;
ll ans=inf;
ll e[maxn+5][maxn+5];

ll p[maxn+5];
void prim(ll s){
	memset(dis,0x3f,sizeof dis);

	memset(vis,0,sizeof vis);
	ll sum=0;
	vis[p[1]]=1,dis[p[1]]=0;

	for(ll i=2;i<=n;i++){
		ll v=p[i];
		ll op=inf;
		for(ll j=1;j<i;j++){

			ll u=p[j];

			if(e[u][v]!=inf&&e[u][v]*(dis[u]+1)<op){

				op=e[u][v]*(dis[u]+1);

				dis[v]=dis[u]+1;

			}
		}
		if(op>=inf)return;
		sum+=op;
	}
	ans=Min(ans,sum);
}

int main(){
	scanf("%lld%lld",&n,&m);

	memset(e,0x3f,sizeof e);
	for(ll i=1;i<=n;i++)e[i][i]=0,p[i]=i;
	for(ll i=1;i<=m;i++){
		ll a,b,c;scanf("%lld%lld%lld",&a,&b,&c);

		e[a][b]=e[b][a]=Min(e[a][b],c);

	}
	for(ll k=1;k<=50000;k++){
		random_shuffle(p+1,p+n+1);
		for(ll i=1;i<=n;i++)prim(i);
	}
	printf("%lld",ans);
	return 0;
}