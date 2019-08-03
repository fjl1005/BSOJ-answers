#include<cstdio>
int G2[1005][1005],G5[1005][1005];
int T2(int x){
	int s=0;
	while(x%2==0){
		x/=2;
		s++;
	}
	return s;
}
int T5(int x){
	int s=0;
	while(x%5==0){
		x/=5;
		s++;
	}
	return s;
}
int Min(int a,int b){
	return a<b?a:b;
}
int main(){
	int x,n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&x);
			G2[i][j]=T2(x);
			G5[i][j]=T5(x);
		}
	}
	for(i=1;i<n;i++){
		G2[i][0]+=G2[i-1][0];
		G5[i][0]+=G5[i-1][0];
	}
	for(i=1;i<m;i++){
		G2[0][i]+=G2[0][i-1];
		G5[0][i]+=G5[0][i-1];
	}
	for(i=1;i<n;i++){
		for(j=1;j<m;j++){
			G2[i][j]+=Min(G2[i-1][j],G2[i][j-1]);
			G5[i][j]+=Min(G5[i-1][j],G5[i][j-1]);
		}
	}
	printf("%d",Min(G2[n-1][m-1],G5[n-1][m-1]));
	return 0;
}