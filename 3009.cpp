#include<cstdio>
int a[1005][1005];
int main() {
//	freopen("3d.in","r",stdin);
//	freopen("3d.out","w",stdout);
	int n,m,i,j,k;
	long long s=0;
	char x;
	scanf("%d%d",&n,&m);
	for(i=1; i<=n; i++) {
		getchar();
		for(j=1; j<=m; j++) {
			x=getchar();
			a[i][j]=x-'0';
		}
	}
	for(i=1; i<=n; i++) {
		for(j=1; j<=m; j++) {
			for(k=1; k<=a[i][j]; k++) {
				if(k==a[i][j]) {
					s++;
				}
				
				if(k==1) {
					s++;
				}
				
				if(j==1) {
					s++;
				}
				if(j>1&&a[i][j-1]<k) {
					s++;
				}
				
				if(j==m) {
					s++;
				}
				if(j<m&&a[i][j+1]<k) {
					s++;
				}
				
				if(i==1) {
					s++;
				}
				if(i>1&&a[i-1][j]<k) {
					s++;
				}
				
				if(i==n) {
					s++;
				}
				if(i<n&&a[i+1][j]<k) {
					s++;
				}
			}
		}
	}
	printf("%d",s);
	return 0;
}
