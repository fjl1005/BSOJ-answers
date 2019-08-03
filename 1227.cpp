#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll maxn=100005;

ll tree[maxn];
inline ll lowbit(ll x){return x&(-x);}
ll query(ll x){ll sum=0;for(ll i=x;i>0;i-=lowbit(i))sum+=tree[i];return sum;}
void update(ll x,ll d){for(ll i=x;i<=maxn;i+=lowbit(i))tree[i]+=d;}
ll n;

int main(){
	while(scanf("%lld",&n)){
		memset(tree,0,sizeof tree);
		if(n==0)break;
		for(ll i=1;i<=n;i++){ll a,b;scanf("%lld%lld",&a,&b);;update(b+1,-1);update(a,1);}
		for(ll i=1;i<=n;i++)printf("%lld ",query(i));puts("");
	}
	return 0;
}