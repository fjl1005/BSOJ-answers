#include<cstdio>
int g[105][105];
int f[105][105];
int main(){
	int m,n;
	
	scanf("%d%d",&m,&n);
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&g[i][j]);
		}
	}
	int k;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			int Max=-1;
			for(k=0;k<=j;k++){
				if(f[i-1][j-k]+g[i][k]>Max){
					Max=f[i-1][j-k]+g[i][k];
				}
			}
			f[i][j]=Max;
		}
	}
	printf("%d",f[n][m]);
	return 0;
}

/*
f[i][j]=max{f[i-1][j-k]+v[i][k]}
*/
