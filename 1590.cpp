#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[25],s=0;
bool book[25];
char map[30],l[100005][15];
void dfs(int step) {
	if(step==n+1) {
		for(int i=1; i<=n; i++) {
			l[s][i]=map[a[i]];
		}
		s++;
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
	int i,j;
	gets(map);
	n=strlen(map);
	sort(map,map+n);
	int s=1;
 	do{
 		printf("%d:",s++);
		puts(map);
	}while(next_permutation(map,map+n));
	return 0;
}