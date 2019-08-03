#include<cstdio>
double f[2005][2005];
double dis[2005];
#define minn -1
bool book[2005];
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int i;
	for(i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			f[i][j]=minn;
			if(i==j) {
				f[i][j]=0;
			}
		}
	}
	for(i=1; i<=m; i++) {
		int tx,ty;
		int tw;
		scanf("%d%d%d",&tx,&ty,&tw);
		f[tx][ty]=1.0-tw/100.0;
		f[ty][tx]=f[tx][ty];
	}
	int s,t;
	scanf("%d%d",&s,&t);
	for(i=1; i<=n; i++) {
		dis[i]=f[s][i];
	}
//	for(i=1; i<=n; i++) {
//		printf("%.9lf ",dis[i]);
//	}
	book[i]=1;
	for(i=1; i<=n-1; i++) {
		int k;
		double Max=minn;
		int j;
		for(j=1; j<=n; j++) {
			if(!book[j]&&dis[j]>Max) {
				Max=dis[j];
				k=j;
			}
		}
		book[k]=1;
		for(j=1; j<=n; j++) {
			if(!book[j]&&f[k][j]!=minn&&f[k][j]*dis[k]>dis[j]) {
				dis[j]=dis[k]*f[k][j];
			}
		}
	}
//	for(i=1; i<=n; i++) {
//		printf("%.9lf ",dis[i]);
//	}
	printf("%.8lf",100.0/dis[t]);
	return 0;
}
