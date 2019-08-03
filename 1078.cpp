#include<cstdio>
int a[1005],dp[1005];

int main() {
	int n,i,j,Max=-1;
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	dp[1]=1;
	for(i=2; i<=n; i++) {
		dp[i]=1;
		for(j=1; j<i; j++) {
			if(a[j]<=a[i]) {
				if(dp[j]>=dp[i]) {
					dp[i]=dp[j]+1;
				}
			}
		}
		if(dp[i]>Max) {
			Max=dp[i];
		}
	}
	printf("%d",Max);
	return 0;
}