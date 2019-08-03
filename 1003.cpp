#include<cstdio>
#include<cstring>

#define ll long long

inline ll Max(ll a,ll b){return a>b?a:b;}

const ll maxn=3005;
char a[maxn],b[maxn];
ll dp[maxn][maxn];
ll n,m;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	gets(a+1),gets(b+1);
	n=strlen(a+1),m=strlen(b+1);
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++){
			dp[i][j]=Max(dp[i][j-1],dp[i-1][j]);
			if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
		}
	printf("%lld",dp[n][m]);
	return 0;
}

