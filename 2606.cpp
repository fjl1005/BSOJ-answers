#include<cstdio>
const int inf=99999999;
int n,m;
int a[1005][1005];
int dis[1005];
int dis1[1005];
int vis[1005];


inline void swap(int &a,int &b) {
	a^=b^=a^=b;
}

int main() {
	int x;
	scanf("%d%d%d",&n,&m,&x);
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
	for(int i=1; i<=n; i++) {
		dis[i]=a[x][i];
	}
	vis[x]=1;
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
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			swap(a[i][j],a[j][i]);
		}
	}
	for(int i=1; i<=n; i++) {
		dis1[i]=inf;
		vis[i]=0;
	}
	for(int i=1; i<=n; i++) {
		dis1[i]=a[x][i];
	}
	vis[x]=1;
	for(int i=1; i<n; i++) {
		int Min=inf,Minn;
		for(int j=1; j<=n; j++) {
			if(dis1[j]<Min&&!vis[j]) {
				Min=dis1[j];
				Minn=j;
			}
		}
		vis[Minn]=1;
		for(int j=1; j<=n; j++) {
			if(!vis[j]&&dis1[Minn]+a[Minn][j]<dis1[j]) {
				dis1[j]=dis1[Minn]+a[Minn][j];
			}
		}
	}
	
//	for(int i=1;i<=n;i++){
//		printf("%d ",dis[i]);
//	}
//	puts("");
//	for(int i=1;i<=n;i++){
//		printf("%d ",dis1[i]);
//	}
//	puts("");
//	
	int Max=-1;
	for(int i=1;i<=n;i++){
		if(dis[i]+dis1[i]>Max){
			Max=dis[i]+dis1[i];
		}
	}
	printf("%d",Max);
	return 0;
}