#include<cstdio>
#define R register
int d[35];
int f[35][35];
int r[35][35];
int dp(int i,int j) {
	if(i>j) {
		return 1;
	}
	if(i==j) {
		return d[i];
	}
	if(f[i][j]>0) {
		return f[i][j];
	}
	for(R int k=i; k<=j; k++) {
		R int t=dp(i,k-1)*dp(k+1,j)+d[k];
		if(t>f[i][j]) {
			f[i][j]=t;
			r[i][j]=k;
		}
	}
	return f[i][j];
}
void print(int i,int j) {
	if(i>j) {
		return;
	}
	if(i==j) {
		printf("%d ",i);
		return;
	}
	printf("%d ",r[i][j]);
	print(i,r[i][j]-1);
	print(r[i][j]+1,j);
	return;
}
int main() {
	int n;
	scanf("%d",&n);
	for(R int i=1; i<=n; i++) {
		scanf("%d",&d[i]);
	}
	printf("%d\n",dp(1,n));
	print(1,n);
	return 0;
}