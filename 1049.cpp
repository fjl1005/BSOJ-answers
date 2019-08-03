#include<cstdio>
int c[1005],w[1005],dp[1005][1005];
int max(int x,int y) {
	return x>y?x:y;
}
int main() {
	int v,n,i,j;
	scanf("%d%d",&v,&n);
	for(i=1; i<=n; i++) {
		scanf("%d%d",&c[i],&w[i]);
	}
	for(i=1; i<=n; i++) {
		for(j=0; j<=v; j++) {
			if(j>=c[i]) {
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-c[i]]+w[i]);
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	printf("%d",dp[n][v]);
	return 0;
}