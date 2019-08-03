#include<cstdio>
bool e[205][205],book[205];
int n;
void dfs(int x) {
	int i;
	for(i=1;i<=n;i++){
		if(e[x][i]&&!book[i]){
			book[i]=1;
			dfs(i);
		}
	}
	return;
}
int main() {
	int m,i,j,x,y,start,s=0;
	scanf("%d%d",&n,&m);
	for(i=0; i<m; i++) {
		scanf("%d%d",&x,&y);
		e[x][y]=1;
	}
	scanf("%d",&start);
	book[start]=1;
	dfs(start);
	for(i=1;i<=n;i++){
		if(book[i]==1){
			s++;
		}
	}
	printf("%d",s);
	return 0;
}
