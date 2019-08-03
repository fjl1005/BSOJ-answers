#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll maxn=1005;
ll n,m;
ll tree[maxn][maxn];
inline ll lowbit(ll x){return x&(-x);}
ll query(ll x,ll y){ll sum=0;for(ll i=x;i>0;i-=lowbit(i))for(ll j=y;j>0;j-=lowbit(j))sum+=tree[i][j];return sum;}
void update(ll x,ll y,ll d){for(ll i=x;i<=n;i+=lowbit(i))for(ll j=y;j<=n;j+=lowbit(j))tree[i][j]+=d;}

ll p[maxn][maxn];
int main(){
	ll t;scanf("%lld",&t);
	while(t--){
		memset(tree,0,sizeof tree);
		scanf("%lld%lld",&n,&m);
		for(ll i=1;i<=m;i++){
			char ch=getchar();while(ch!='C'&&ch!='Q')ch=getchar();
			if(ch=='C'){
				ll x1,y1,x2,y2;
				scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
				update(x1,y1,1);update(x2+1,y2+1,1);
				update(x1,y2+1,-1);update(x2+1,y1,-1);
			}else{
				ll x,y;scanf("%lld%lld",&x,&y);
				printf("%lld\n",query(x,y)%2);
			}
		}
		puts("");
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