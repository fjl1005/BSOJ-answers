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
int u[500005],v[500005];
int first[500005],next[500005];
int tot;
void add(int x,int y) {
	tot++;
	u[tot]=x;
	v[tot]=y;
	next[tot]=first[x];
	first[x]=tot;
}
int p[500005][35];
int vis[500005];
int dep[500005];
void dfs(int x) {
	vis[x]=1;
	for(int i=first[x]; i; i=next[i]) {
		if(!vis[v[i]]) {
			dep[v[i]]=dep[x]+1;
			p[v[i]][0]=x;
			dfs(v[i]);
		}
	}
}

int n,m;
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
	dep[1]=1;
	dfs(1);
	for(int j=1; j<=30; j++) {
		for(int i=1; i<=n; i++) {
			p[i][j]=p[p[i][j-1]][j-1];
		}
	}
}

int cale(int a,int b,int l){
	return Abs(dep[l]-dep[a])+Abs(dep[l]-dep[b]); 
}
struct f{
	int l,s;
};

f ans(int a,int b,int c){
	int l1=lca(a,b);
	int l2=lca(l1,c);
	f ff;
	ff.l=l1;
	ff.s=cale(a,b,l1)+cale(c,l1,l2);
	return ff;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<n; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		add(b,a);
		add(a,b);
	}
	init();
	for(int i=1; i<=m; i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		f minn;
		minn.s=inf;
		f tt;
		tt=ans(a,b,c);
		if(tt.s<minn.s){
			minn=tt;
		}
		tt=ans(a,c,b);
		if(tt.s<minn.s){
			minn=tt;
		}
		tt=ans(b,c,a);
		if(tt.s<minn.s){
			minn=tt;
		}
		printf("%d %d\n",minn.l,minn.s);
	}
	return 0;
}
