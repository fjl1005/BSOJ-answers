#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 2500;
ll b[maxn];
ll n,m;
ll c0[maxn][maxn],c1[maxn][maxn],c2[maxn][maxn],c3[maxn][maxn];

inline ll lowbit(ll x){return x&(-x);}
ll query(ll x,ll y){
	ll sum=0;
	for(ll i=x;i>0;i-=lowbit(i))
		for(ll j=y;j>0;j-=lowbit(j)){
			sum+=c0[i][j]*(x+1)*(y+1);
			sum-=c1[i][j]*(y+1);
			sum-=c2[i][j]*(x+1);
			sum+=c3[i][j];
		}
	return sum;
}
void update(ll x,ll y,ll d){
	for(ll i=x;i<=n;i+=lowbit(i))
		for(ll j=y;j<=m;j+=lowbit(j)){
			c0[i][j]+=d;
			c1[i][j]+=d*x;
			c2[i][j]+=d*y;
			c3[i][j]+=d*x*y;
		}
}
int main(){
	scanf("%lld%lld",&n,&m);ll x;
	while(scanf("%lld",&x)!=EOF){
		if(x==1){
			ll a,b,c,d,e;scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);
			update(a,b,e);update(a,d+1,-e);update(c+1,b,-e);update(c+1,d+1,e);
		}
		if(x==2){
			ll a,b,c,d;scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
			printf("%lld\n",query(c,d)-query(c,b-1)-query(a-1,d)+query(a-1,b-1));
		}
	}
	return 0;
}
/*
4 4
1 1 1 3 3 2
1 2 2 4 4 1
2 2 2 3 3
*/