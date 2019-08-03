#include<cstdio>
#include<cmath>

int dis[105];
int f[105][105];
bool book[105];
#define maxx 999999
int main(){
	int n,k;
	int i;
	scanf("%d%d",&n,&k);
	int j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&f[i][j]);
			if(f[i][j]==-1){
				f[i][j]=maxx;
			}
		}
	}
	int s;
	s=k;
	s++;
	for(i=1;i<=n;i++){
		dis[i]=f[s][i];
	}
//	for(i=1;i<=n;i++){
//		printf("%d ",dis[i]);
//	}
	book[s]=1;
	for(i=1;i<=n-1;i++){
		int Min=maxx,k;
		int j;
		for(j=1;j<=n;j++){
			if(!book[j]&&dis[j]<Min){
				Min=dis[j];
				k=j;
			}
		}
		book[k]=1;
		for(j=1;j<=n;j++){
			if(!book[j]&&f[k][j]!=maxx&&f[k][j]+dis[k]<dis[j]){
				dis[j]=f[k][j]+dis[k];
			}
		}
	}
	for(i=1;i<=n;i++){
		printf("%d ",dis[i]);
	}
	return 0;
}
