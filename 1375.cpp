#include<cstdio>

#define inf 1<<30
#define random(a,b) (rand()*rand())%(b-a+1)+a
inline int Max(int a,int b) {
	return a>b?a:b;
}
inline int Min(int a,int b) {
	return a<b?a:b;
}
inline int Abs(int x) {
	return x<0?-x:x;
}
inline void Swap(int &a,int &b) {
	a^=b^=a^=b;
}
int u[200005],v[200005];
int first[200005],next[200005];
int tot;
void add(int x,int y) {
	tot++;
	u[tot]=x;
	v[tot]=y;
	next[tot]=first[x];
	first[x]=tot;
}
int vis[200005];
int dep[200005];
void dfs(int x) {
	vis[x]=1;
	for(int i=first[x]; i; i=next[i]) {
		if(!vis[v[i]]) {
			dep[v[i]]=dep[x]+1;
			dfs(v[i]);
		}
	}
}

int n,m;
int p[400005][35];
int lca(int a,int b) {
	if(dep[a]<dep[b]) {
		Swap(a,b);
	}
	for(int i=30; i>=0; i--) {
		if(dep[a]-(1<<i)>=dep[b]) {
			a=p[a][i];
		}
	}
	if(a==b) {
		return a;
	}
	for(int i=30; i>=0; i--) {
		if(p[a][i]!=p[b][i]) {
			a=p[a][i];
			b=p[b][i];
		}
	}
	return p[a][0];
}

int root;
void init() {
	dep[root]=1;
	dfs(root);
	for(int j=1; j<=30; j++) {
		for(int i=1; i<=n; i++) {
			p[i][j]=p[p[i][j-1]][j-1];
		}
	}
}


int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<n; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		p[b][0]=a;
		if(p[a][0]==0) {
			root=a;
		}
	}
	init();
	for(int i=1; i<=m; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",lca(a,b));
	}
	return 0;
}

