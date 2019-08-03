#include<cstdio>
int a[25][25];
int f[25][25][25][25];
int Max(int a,int b){
	return a>b?a:b;
}
int max(int a,int b,int c,int d){
	a=Max(a,c);
	b=Max(b,d);
	return Max(a,b);
}
int main() {
	int n;
	scanf("%d",&n);
	int i;
	int tx,ty;
	int ts;
	while(1) {
		scanf("%d%d%d",&tx,&ty,&ts);
		if(tx==0&&ty==0&&ts==0) {
			break;
		}
		a[tx][ty]=ts;
	}
	int j,k,l;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				for(l=1;l<=n;l++){
					f[i][j][k][l]=max(f[i-1][j][k-1][l],f[i-1][j][k][l-1],f[i][j-1][k-1][l],f[i][j-1][k][l-1])+a[i][j]+a[k][l];
					if(i==k&&j==l){
						f[i][j][k][l]-=a[i][j];
					}
				}
			}
		}
	}
	printf("%d",f[n][n][n][n]);
	return 0;
}