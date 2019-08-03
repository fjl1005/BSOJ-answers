#include <cstdio>
#define inf 21000000
int fmin[1000][1000];
int fmax[1000][1000];
int g[1000][1000];
int a[1000],minn=-2100000;
int main() {
	int n;
	int i;
	scanf("%d",&n);
	for (i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	for (i=1; i<=n; i++)
		g[i][i]=a[i];
	int j;
	for (i=1; i<=n; i++) {
		for (j=i+1; j<=n; j++) {
			g[i][j]=g[i][j-1]+a[j];
		}
	}
	for (i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			fmin[i][j]=(i!=j)?inf:0;
		}
	}
	int p;
	for (p=1; p<n; p++) {
		for (i=1; i<=n-p; i++) {
			int j=i+p;
			for (int k=i; k<=j-1; k++) {
				fmin[i][j]=(fmin[i][j]>fmin[i][k]+fmin[k+1][j]+g[i][j])?fmin[i][k]+fmin[k+1][j]+g[i][j]:fmin[i][j];
				fmax[i][j]=(fmax[i][j]>fmax[i][k]+fmax[k+1][j]+g[i][j])?fmax[i][j]:fmax[i][k]+fmax[k+1][j]+g[i][j];
			}
		}
	}
	printf("%d\n%d",fmin[1][n],fmax[1][n]);
	return 0;
}