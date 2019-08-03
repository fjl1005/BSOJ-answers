#include<cstdio>
bool book[15];
int a[15];
bool ss[50]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1};
int n;
void dfs(int step) {
	bool flag=1;
	while(step==n+1) {
		if(!ss[a[1]+a[n]]) {
			break;
		}
		for(int i=1; i<n; i++) {
			if(!ss[a[i]+a[i+1]]) {
				flag=0;
				break;
			}
		}
		if(!flag) {
			break;
		}
		for(int i=1; i<=n; i++) {
			printf("%d ",a[i]);
		}
		puts("");
		break;
	}
	for(int i=1; i<=n; i++) {
		if(book[i]==0) {
			a[step]=i;
			book[i]=1;
			dfs(step+1);
			book[i]=0;
		}
	}
	return;
}
int main() {
	scanf("%d",&n);
	if(n%2==1) {
		printf("NO");
		return 0;
	}
	dfs(1);
	return 0;
}