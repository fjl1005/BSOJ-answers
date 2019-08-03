#include<cstdio>
int a[355],b[8],dp[55][55][55][55];
int max(int x,int y) {
	return x>y?x:y;
}
int main() {
	int n,m,i,j,k,l,t;
	scanf("%d%d",&m,&n);
	for(i=1; i<=m; i++) {
		scanf("%d",&a[i]);
	}
	for(i=1; i<=n; i++) {
		scanf("%d",&t);
		b[t]++;
	}
	dp[0][0][0][0]=a[1];
	for(i=0; i<=b[1]; i++) {
		for(j=0; j<=b[2]; j++) {
			for(k=0; k<=b[3]; k++) {
				for(l=0; l<=b[4]; l++) {
					if(!(i||j||k||l)) {
						continue;
					}
					int a1=0,a2=0,a3=0,a4=0,p=a[i+j*2+k*3+l*4+1];
					if(i) {
						a1=dp[i-1][j][k][l];
					}
					if(j) {
						a2=dp[i][j-1][k][l];
					}
					if(k) {
						a3=dp[i][j][k-1][l];
					}
					if(l) {
						a4=dp[i][j][k][l-1];
					}
					dp[i][j][k][l]=max(max(a1,a2),max(a3,a4))+p;
				}
			}
		}
	}
	printf("%d",dp[b[1]][b[2]][b[3]][b[4]]);
	return 0;
}