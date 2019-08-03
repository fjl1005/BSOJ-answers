#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 100000;
ll a[maxn],b[maxn];
ll sum[maxn];
ll n,m;
ll c0[maxn],c1[maxn];

inline ll lowbit(ll x){return x&(-x);}
ll query(ll tree[],ll x){ll sum=0;for(ll i=x;i>0;i-=lowbit(i))sum+=tree[i];return sum;}
void update(ll tree[],ll x,ll d){for(ll i=x;i<=n;i+=lowbit(i))tree[i]+=d;}
int main(){
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);sum[i]=sum[i-1]+a[i];
	}
	while(m--){
		char ch=getchar();while(ch!='Q'&&ch!='C')ch=getchar();
		if(ch=='C'){
			ll a,b,c;scanf("%lld%lld%lld",&a,&b,&c);
			update(c0,a,c  );update(c0,b+1,-      c);
			update(c1,a,c*a);update(c1,b+1,-(b+1)*c);
		}
		if(ch=='Q'){
			ll a,b;scanf("%lld%lld",&a,&b);
			ll ans =sum[b]+(b+1)*query(c0,b)-query(c1,b);
			   ans-=sum[a-1]+a*query(c0,a-1)-query(c1,a-1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}