#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll maxn=1050;

ll tree[maxn][maxn];
inline ll lowbit(ll x){return x&(-x);}
ll query(ll x,ll y){ll sum=0;for(ll i=x;i>0;i-=lowbit(i))for(ll j=y;j>0;j-=lowbit(j))sum+=tree[i][j];return sum;}
void update(ll x,ll y,ll d){for(ll i=x;i<=maxn;i+=lowbit(i))for(ll j=y;j<=maxn;j+=lowbit(j))tree[i][j]+=d;}
ll s;

int main(){
	ll code;
	while(scanf("%lld",&code)){
		if(code==0){scanf("%lld",&s);continue;}
		if(code==1){ll x,y,d;scanf("%lld%lld%lld",&x,&y,&d);x++,y++;update(x,y,d);}
		if(code==2){ll l,r,b,t;scanf("%lld%lld%lld%lld",&l,&r,&b,&t);l++,r++,b++,t++;printf("%lld\n",query(b,t)-query(l-1,t)-query(b,r-1)+query(l-1,r-1));}
		if(code==3)break;
	}
	return 0;
}
/*
0 4
1 1 2 3
2 0 0 2 2
1 1 2 -1
2 1 1 2 3
3
*/