#include<cstdio>
int f[205][10];
int main(){
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	for(i=0;i<205;i++){
		f[i][1]=1;
	}
	for(i=2;i<=k;i++){
		for(j=0;j<=n-k;j++){
			if(i>j){
				f[j][i]=f[j][i-1];
			}
			else{
				f[j][i]=f[j][i-1]+f[j-i][i];
			}
		}
	}
	printf("%d",f[n-k][k]);
	return 0;
}