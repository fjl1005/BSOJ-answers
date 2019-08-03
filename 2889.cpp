#include<cstdio>
#include<algorithm>
using std::sort;

struct edge {
	int u,v,w;
} t[50005];
int tot;
void add(int a,int b,int c) {
	tot++;
	t[tot].u=a,t[tot].v=b,t[tot].w=c;
}

int read() {
	char ch=getchar();
	int f=1,s=0;
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	};
	while(ch>='0'&&ch<='9') {
		s=(s<<1)+(s<<3)+ch-'0';
		ch=getchar();
	}
	return f*s;
}

int cmp(edge a,edge b) {
	return a.w<b.w;
}

int f[305];
int gf(int x) {
	if(x==f[x]) {
		return x;
	}
	f[x]=gf(f[x]);
	return f[x];
}

void merge(int a,int b) {
	int fa=gf(a);
	int fb=gf(b);
	if(fa!=fb) {
		f[fa]=fb;
	}
}

int n,m;

int kru(int k) {
	for(int i=1; i<=n; i++) {
		f[i]=i;
	}
	int Maxx=-1,Minn=1<<30;
	int h=0;
	for(int i=k; i<=m&&h<n-1; i++) {
		if(gf(t[i].u)!=gf(t[i].v)) {
			h++;
			merge(t[i].u,t[i].v);
			if(t[i].w>Maxx) {
				Maxx=t[i].w;
			}
			if(t[i].w<Minn) {
				Minn=t[i].w;
			}
		}
	}
	if(h!=n-1){
		return -1;
	}
	return Maxx-Minn;
}

int main() {
	n=read(),m=read();
	for(int i=1; i<=m; i++) {
		int a=read()+1,b=read()+1,c=read();
		add(a,b,c);
	}
	sort(t+1,t+m+1,cmp);
	int ans=1<<30;
	for(int i=1; i<=m; i++) {
		int sum=kru(i);
		if(sum!=-1){
			if(sum<ans){
				ans=sum;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
