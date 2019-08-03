#include<cstdio>
int map[1005][1005];
int f(int x,int y) {
	int a=map[x-1][y-1],b=map[x-1][y],c=map[x][y-1];
	if(a>b) {
		a=b;
	}
	if(a>c) {
		a=c;
	}
	return a;
}
int main() {
	int n,m,i,j,Max=0;
	scanf("%d%d",&n,&m);
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			scanf("%d",&map[i][j]);
		}
	}
	for(i=1; i<n; i++) {
		for(j=1; j<m; j++) {
			if(map[i][j]) {
				map[i][j]+=f(i,j);
				if(map[i][j]>Max) {
					Max=map[i][j];
				}
			}
		}
	}
	printf("%d",Max);
	return 0;
}