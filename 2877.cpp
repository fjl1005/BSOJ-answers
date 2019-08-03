#include<cstdio>
bool a[205][205],book[205];
int n,s,sum=0,t[205];
void dfs(int x,int s) {
	if(s==n) {
		sum++;
		return;
	}
	int i;
	for(i=1; i<=n; i++) {
		if(a[x][i]&&!book[i]) {
			book[i]=1;
			dfs(i,s+1);
			book[i]=0;
		}
	}
	return;
}
int main() {
//	freopen("letter.in","r",stdin);
//	freopen("letter.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			book[j]=0;
		}
		book[i]=1;
		dfs(i,1);
	}
	printf("%d",sum);
	return 0;
}
