#include<cstdio>
int a[55][55];
int f[55][55][55][55];
int Max(int a,int b){
	return a>b?a:b;
}
int max(int a,int b,int c,int d){
	a=Max(a,c);
	b=Max(b,d);
	return Max(a,b);
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int i;
	int j,k,l;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			for(k=1;k<=n;k++){
				for(l=1;l<=m;l++){
					f[i][j][k][l]=max(f[i-1][j][k-1][l],f[i-1][j][k][l-1],f[i][j-1][k-1][l],f[i][j-1][k][l-1])+a[i][j]+a[k][l];
					if(i==k&&j==l){
						f[i][j][k][l]-=a[i][j];
					}
				}
			}
		}
	}
	printf("%d",f[n][m][n][m]);
	return 0;
}