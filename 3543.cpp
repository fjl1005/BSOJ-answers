#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[25],s=0;
bool book[25];
char map[30];
void dfs(int step) {
	if(step==n+1) {
		s++;
		printf("%d:",s);
		for(int i=1;i<=n;i++){
			printf("%c",map[a[i]]);
		}
		puts("");
	} else for(int i=1; i<=n; i++) {
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
	gets(map+1);
	n=strlen(map+1);
	sort(map+1,map+n+1);
	dfs(1);
	return 0;
}