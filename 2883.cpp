#include<cstdio>
const int inf=99999999;
int n,m;
int a[505][505];
int prt[505];
int dis[505];
int vis[505];

void out(int t) {
	if(prt[t]==t) {
		return;
	}
	out(prt[t]);
	printf(" %d",t);
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			a[i][j]=inf;
		}
	}
	for(int i=1; i<=n; i++) {
		a[i][i]=0;
		dis[i]=inf;
	}
	for(int i=1; i<=m; i++) {
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=z;
	}
	int s,t;
	scanf("%d%d",&s,&t);
	for(int i=1; i<=n; i++) {
		dis[i]=a[s][i];
	}
//	for(int i=1; i<=n; i++) {
//		printf("%d ",dis[i]);
//	}
//	puts("");
	vis[s]=1;
	for(int i=1; i<n; i++) {
		int Min=inf,Minn;
		for(int j=1; j<=n; j++) {
			if(dis[j]<Min&&!vis[j]) {
				Min=dis[j];
				Minn=j;
			}
		}
		vis[Minn]=1;
		for(int j=1; j<=n; j++) {
			if(!vis[j]&&dis[Minn]+a[Minn][j]<dis[j]) {
				dis[j]=dis[Minn]+a[Minn][j];
				prt[j]=Minn;
			}
		}
	}
//	for(int i=1; i<=n; i++) {
//		printf("%d ",dis[i]);
//	}
//	puts("");
	printf("%d",dis[t]);
	printf("\n%d",s);
	out(t);
	return 0;
}
/*
5 7
1 2 10
1 4 30
1 5 100
2 3 50
3 5 10
4 3 20
4 5 60
1 5
*/