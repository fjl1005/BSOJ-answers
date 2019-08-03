#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll maxn=105;
const ll maxm=1005;
ll n,m;
ll tree[maxn][maxn][maxn];
inline ll lowbit(ll x){return x&(-x);}
ll query(ll x,ll y,ll z){ll sum=0;for(ll i=x;i>0;i-=lowbit(i))for(ll j=y;j>0;j-=lowbit(j))for(ll k=z;k>0;k-=lowbit(k))sum+=tree[i][j][k];return sum;}
void update(ll x,ll y,ll z,ll d){for(ll i=x;i<=n;i+=lowbit(i))for(ll j=y;j<=n;j+=lowbit(j))for(ll k=z;k<=n;k+=lowbit(k))tree[i][j][k]+=d;}

int main(){
	while(scanf("%lld%lld",&n,&m)!=EOF){
		memset(tree,0,sizeof tree);
		for(ll i=1;i<=m;i++){
			ll x;scanf("%lld",&x);
			if(x==1){
				ll x1,y1,z1,x2,y2,z2;
				scanf("%lld%lld%lld%lld%lld%lld",&x1,&y1,&z1,&x2,&y2,&z2);
				update(x1,y1,z1,3);update(x2+1,y2+1,z2+1,3);
				update(x2+1,y1,z1,-1);update(x1,y2+1,z1,-1);update(x1,y1,z2+1,-1);
				update(x2+1,y2+1,z1,-1);update(x2+1,y1,z2+1,-1);update(x1,y2+1,z2+1,-1);
			}
			if(x==0){
				ll x,y,z;scanf("%lld%lld%lld",&x,&y,&z);
				printf("%lld\n",query(x,y,z)%2);
			}
		}
	}
	return 0;
}
/*
1
2 10
C 2 1 2 2
Q 2 2
C 2 1 2 1
Q 1 1
C 1 1 2 1
C 1 2 1 2
C 1 1 2 2
Q 1 1
C 1 1 2 1
Q 2 1

*/