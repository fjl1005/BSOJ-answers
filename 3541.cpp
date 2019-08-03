#include<cstdio>
bool a[105][105];
struct t {
	int s;
	long long sameway;
} f[105][105];
int Max(int a,int b) {
	return a>b?a:b;
}
int main() {
	int i,j,n,m;
	char x;
	scanf("%d %d\n",&n,&m);
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			x=getchar();
			a[i][j]=x-'0';
		}
		getchar();
	}
	f[0][0].s=a[0][0];
	f[0][0].sameway=1;
	for(i=1; i<n; i++) {
		f[i][0].s=f[i-1][0].s+a[i][0];
		f[i][0].sameway=1;
	}
	for(i=1; i<m; i++) {
		f[0][i].s=f[0][i-1].s+a[0][i];
		f[0][i].sameway=1;
	}
	for(i=1; i<n; i++) {
		for(j=1; j<m; j++) {
			if(f[i-1][j].s==f[i][j-1].s) {
				f[i][j].s=f[i-1][j].s+a[i][j];
				f[i][j].sameway=f[i-1][j].sameway+f[i][j-1].sameway;
			} else {
				if(f[i-1][j].s>f[i][j-1].s) {
					f[i][j].s=f[i-1][j].s+a[i][j];
					f[i][j].sameway=f[i-1][j].sameway;
				} else {
					f[i][j].s=f[i][j-1].s+a[i][j];
					f[i][j].sameway=f[i][j-1].sameway;
				}
			}
		}
	}
	printf("%d\n%lld",f[n-1][m-1].s,f[n-1][m-1].sameway);
	return 0;
}