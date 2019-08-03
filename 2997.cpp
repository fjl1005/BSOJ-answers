#include<cstdio>
int a[5][200005],f[5][200005];
int min(int x,int y) {
	return x<y?x:y;
}
int main() {
	int n,i;
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
	}
	f[1][1]=a[1][1];
	f[2][1]=a[2][1];
	f[3][1]=a[3][1];
	for(i=2; i<=n; i++) {
		f[1][i]=min(f[2][i-1],f[3][i-1])+a[1][i];
		f[2][i]=min(f[1][i-1],f[3][i-1])+a[2][i];
		f[3][i]=min(f[1][i-1],f[2][i-1])+a[3][i];
	}
	printf("%d",min(min(f[1][n],f[2][n]),f[3][n]));
	return 0;
}