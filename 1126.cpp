#include<cstdio>
#include<algorithm>
using namespace std;

struct person {
	int num,money;
} p[3005];

int n,m,r;

int f[3005];
int mon[3005];
int vis[3005];

int u[8005],v[8005];
int first[3005],next[8005];
int tot;
void add(int a,int b) {
	tot++;
	u[tot]=a,v[tot]=b;
	next[tot]=first[a];
	first[a]=tot;
}

int cmp(person a,person b) {
	return a.money<b.money;
}
void dfs(int x,int root) {
	if(f[x]!=root) {
		f[x]=root;
		for(int i=first[x]; i; i=next[i]) {
			dfs(v[i],root);
		}
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++) {
		scanf("%d%d",&p[i].num,&p[i].money);
		mon[p[i].num]=p[i].money;
	}
	sort(p+1,p+m+1,cmp);
	scanf("%d",&r);
	for(int i=1; i<=r; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for(int i=1; i<=m; i++) {
		if(f[p[i].num]==0) {
			dfs(p[i].num,p[i].num);
		}
	}
	int sum=0;
	for(int i=1; i<=n; i++) {
		if(f[i]==0) {
			printf("NO\n%d",i);
			return 0;
		}
		if(!vis[f[i]]) {
			vis[f[i]]=1;
			sum+=mon[f[i]];
//			printf("%d ",i);
		}
	}
	printf("YES\n%d",sum);
	return 0;
}