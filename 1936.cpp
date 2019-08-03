#include<cstdio>
int w[1005];
int c(int n) {
	int i;
	int s=0;
	for(i=1; i<=n/2; i++) {
		if(n%i==0) {
			s+=i;
		}
	}
	return s;
}
void init() {
	int i;
	for(i=1; i<=1000; i++) {
		w[i]=c(i);
	}
}

int f[1005][1005];
int max(int a,int b){
	return a>b?a:b;
}
int main() {
	init();
	int t;
	scanf("%d",&t);
	int i,j;
	for(i=1; i<=1000; i++) {
		for(j=0; j<=t; j++) {
			if(j>=i) {
				f[i][j]=max(f[i-1][j],f[i-1][j-i]+w[i]);
			} else {
				f[i][j]=f[i-1][j];
			}
		}
	}
	printf("%d",f[1000][t]);
	return 0;
}