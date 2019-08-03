#include<cstdio>
int f[45][25][25][25];
int a[25][25];
int Max(int a,int b) {
	return a>b?a:b;
}

int maxx(int a,int b,int c,int d,int e,int f,int g,int h) {
	return Max(Max(Max(a,b),Max(c,d)),Max(Max(e,f),Max(g,h)));
}

int Maxx(int k,int x1,int x2,int x3) {
	return maxx(f[k-1][x1][x2][x3],f[k-1][x1-1][x2][x3],f[k-1][x1-1][x2-1][x3],f[k-1][x1-1][x2][x3-1],f[k-1][x1-1][x2-1][x3-1],f[k-1][x1][x2-1][x3],f[k-1][x1][x2-1][x3-1],f[k-1][x1][x2][x3-1]);
}

int main() {
	int k;
	int x1,x2,x3;
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			scanf("%d",&a[i][j]);
		}
	}
	f[2][1][1][1]=a[1][1];
	int tt=2*n;
	for(k=3; k<=tt; k++) {
		for(x1=1; x1<=n; x1++) {
			for(x2=1; x2<=n; x2++) {
				for(x3=1; x3<=n; x3++) {
					f[k][x1][x2][x3]=Maxx(k,x1,x2,x3);
					f[k][x1][x2][x3]+=a[x1][k-x1];
					if(x2!=x1) {
						f[k][x1][x2][x3]+=a[x2][k-x2];
					}
					if(x3!=x1&&x3!=x2){
						f[k][x1][x2][x3]+=a[x3][k-x3];
					}

				}
			}
		}
	}
	printf("%d",f[tt][n][n][n]);
	return 0;
}
