#include<cstdio>
int u[10005],v[10005];
int first[1005],next[10005];
int tot=0;
void add(int x,int y){
	++tot;
	u[tot]=x,v[tot]=y;
	next[tot]=first[x];
	first[x]=tot;
}

int read(){
	char ch=getchar();int f=1,s=0;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return f*s;
}

int vis[1005];
int size;
void dfs(int x){
	vis[x]=1;
	for(int i=first[x];i;i=next[i]){
		if(!vis[v[i]]){
			size++;
			dfs(v[i]);
		}
	}
}

int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		add(x,y);
//		add(y,x);
	}
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	int ans=n*(n-1)>>1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			vis[j]=0;
		}
		size=0;
		dfs(i);
		ans-=size;
	}
	printf("%d",ans);
	return 0;
}


