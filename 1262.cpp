#include <cstdio>
char a[45];
int n,m,maxs;
void dfs(int t,int s,int l) {
	int xs=0;
	int i;
	if(t==m) {
		for(i=l; i<n; i++) {
			xs=xs*10+a[i]-'0';
		}
		if(s*xs>maxs) {
			maxs=s*xs;
		}
		return ;
	}
	for(i=l; i<n; i++) {
		xs=xs*10+a[i]-'0';
		dfs(t+1,s*xs,i+1);
	}
	return ;
}
int main() {
	scanf("%d%d",&n,&m);
	getchar();
	gets(a);
	dfs(0,1,0);
	printf("%d",maxs);
	return 0;
}