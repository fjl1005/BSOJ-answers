#include<cstdio>
#include<algorithm>
using namespace std;

#define ll long long

inline ll Max(ll a,ll b){return a>b?a:b;}

const ll maxn = 30005;

struct p{
	ll l,r,val;
	bool operator < (const p &a) const{if(r!=a.r)return r<a.r;return l<a.l;}
}a[maxn];

ll n;
ll dp[maxn];
ll ans=0;

int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld%lld%lld",&a[i].l,&a[i].r,&a[i].val);
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		dp[i]=a[i].val;
		for(ll j=1;j<i;j++){
			if(a[j].r<=a[i].l)
				dp[i]=Max(dp[i],dp[j]+a[i].val);
		}
		ans=Max(ans,dp[i]);
	}
	printf("%lld",ans);
	return 0;
}

