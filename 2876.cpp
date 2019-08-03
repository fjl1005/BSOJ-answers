#include<cstdio>
#include<queue>
using namespace std;
bool e[205][205],book[205];
queue<int> q;
int n;
int main() {
	int m,i,j,x,y,start,s=0;
	scanf("%d%d",&n,&m);
	for(i=0; i<m; i++) {
		scanf("%d%d",&x,&y);
		e[x][y]=1;
		e[y][x]=1;
	}
	scanf("%d",&start);
	q.push(start);
	book[start]=1;
	while(!q.empty()){
		printf("%d ",q.front());
		for(i=1;i<=n;i++){
			if(!book[i]&&e[q.front()][i]){
				book[i]=1;
				q.push(i);
			}
		}
		q.pop();
	}
	return 0;
}