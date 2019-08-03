#include<cstdio>
int u[105],w[105];
int f[105][30005];
int max(int a,int b) {
	return a>b?a:b;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int i;
	for(i=1; i<=m; i++) {
		scanf("%d%d",&u[i],&w[i]);
		w[i]=w[i]*u[i];
	}
	int j;
	for(i=1; i<=m; i++) {
		for(j=1; j<=n; j++) {
			f[i][j]=f[i-1][j];
			if(u[i]<=j) {
				f[i][j]=max(f[i][j],f[i-1][j-u[i]]+w[i]);
			}
		}
	}
	printf("%d",f[m][n]);
	return 0;
}