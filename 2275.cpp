#include<cstdio>
long long f[1005][1005],a[1005][1005];
int min(int a,int b) {
	return a<b?a:b;
}
int main() {
	int n,i,j;
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			scanf("%lld",&a[i][j]);
		}
	}
	f[1][1]=a[1][1];
	for(i=2; i<=n; i++) {
		f[i][1]=f[i-1][1]+a[i][1];
	}
	for(i=2; i<=n; i++) {
		f[1][i]=f[1][i-1]+a[1][i];
	}
	for(i=2; i<=n; i++) {
		for(j=2; j<=n; j++) {
			f[i][j]=min(f[i-1][j],f[i][j-1])+a[i][j];
		}
	}
	printf("%lld",f[n][n]);
	return 0;
}