#include<cstdio>
const int inf=99999999;
int a[5005],b[5005],v[5005];
int n,m;
int dis[1005];
int first[1005],next[5005];

int tot;
void add(int x,int y,int z) {
	++tot;
	a[tot]=x;
	b[tot]=y;
	v[tot]=z;
	next[tot]=first[x];
	first[x]=tot;
}
void init(){
	tot=0;
	for(int i=1;i<=n;i++){
		dis[i]=0;
		first[i]=0;
	}
}
int bellman(int sv) {
	dis[sv]=0;
	for(int i=1; i<n; i++) {
		for(int j=1; j<=m; j++) {
			if(dis[a[j]]+v[j]<dis[b[j]]) {
				dis[b[j]]=dis[a[j]]+v[j];
			}
		}
	}
	for(int i=1; i<n; i++) {
		for(int j=1; j<=m; j++) {
			if(dis[a[j]]+v[j]<dis[b[j]]) {
				return -1;
			}
		}
	}
	return 0;
}
int main() {
	scanf("%d%d",&n,&m);
	init();
	for(int i=1; i<=m; i++) {
		int t1,t2,t3;
		scanf("%d%d%d",&t1,&t2,&t3);
		add(t2,t1,t3);
	}
	if(bellman(0)){
		printf("NO SOLUTION");
	}else{
		int Min=inf;
		for(int i=1;i<=n;i++){
//			printf("%d ",dis[i]);
			if(dis[i]<Min){
				Min=dis[i];
			}
		}
//		printf("%d\n",Min);
		Min=-Min;
		for(int i=1;i<=n;i++){
			dis[i]+=Min;
			printf("%d\n",dis[i]);
		}
	}
	return 0;
}