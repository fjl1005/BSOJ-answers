#include<cstdio>
int f[50][50];
int main(){
	int i,j,k,l,m,n;
	scanf("%d%d",&n,&m);
	f[0][1]=1;
	for(i=1;i<=m;i++){
		for(j=2;j<n;j++){
			f[i][j]=f[i-1][j+1]+f[i-1][j-1];
			f[i][1]=f[i-1][2]+f[i-1][n];
			f[i][n]=f[i-1][1]+f[i-1][n-1];
		}
	}
	printf("%d",f[m][1]);
	return 0;
}