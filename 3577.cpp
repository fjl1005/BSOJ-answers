#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=200005;
const ll inf=10000005;
ll dp[maxn];
ll a[maxn],q[maxn],g[maxn],head=1,tail=0;
ll n,m;
int main(){
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(ll i=1;i<=m;i++){
		dp[i]=a[i];
		while(q[tail]>dp[i])tail--;
		q[++tail]=dp[i];g[tail]=i;
	}
	for(ll i=m+1;i<=n;i++){
		while(i-g[head]>m)head++;
		dp[i]=a[i]+q[head];
		while(q[tail]>dp[i])tail--;
		q[++tail]=dp[i];g[tail]=i;
	}
	ll ans=inf;
	for(ll i=n-m+1;i<=n;i++)ans=min(ans,dp[i]);
	printf("%lld",ans);
	return 0;
}

