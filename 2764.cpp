#include<bits/stdc++.h>
using namespace std;
#define Inc(i,L,r) for(register int i=(L);i<=(r);++i)
const int N = 1e5+10;
struct Edge{
	int to[N<<1],next[N<<1],w[N<<1];
	int cnt,h[N];
	inline void add(int x,int y,int z){
		next[++cnt]=h[x];
		to[cnt]=y;
		w[cnt]=z;
		h[x]=cnt;
	}
}e;
int n,k,G,sum,Minsiz,siz[N];
int ans,dis[N];
bool vst[N];
inline void init(){
	scanf("%d%d",&n,&k);
	Inc(i,1,n-1){
		int x,y,w;scanf("%d%d%d",&x,&y,&w);
		e.add(x,y,w),e.add(y,x,w);
	}
	sum=n;
}
void FG(int x,int fa){ 
	int Maxsiz=0;
	siz[x]=1;
	for(int p=e.h[x];p;p=e.next[p])if(e.to[p]^fa&&!vst[e.to[p]]){
		FG(e.to[p],x);
		siz[x]+=siz[e.to[p]];
		Maxsiz=max(Maxsiz,siz[e.to[p]]);
	}
	Maxsiz=max(Maxsiz,sum-siz[x]);
	if(Maxsiz<Minsiz)G=x,Minsiz=Maxsiz;
}
void FD(int x,int fa,int dist){ 
	dis[++dis[0]]=dist;
	for(int p=e.h[x];p;p=e.next[p])if(e.to[p]^fa&&!vst[e.to[p]]){
		FD(e.to[p],x,dist+e.w[p]);
	}
}
void Cal(int x,int dist,int cmd){
	dis[0]=0;
	FD(x,0,dist);
	sort(dis+1,dis+dis[0]+1);
	int L=1,r=dis[0];
	while(L<r){
		if(dis[L]+dis[r]<=k)ans+=(r-L)*cmd,++L;
		else --r;
	}
}
void work(int x){
	Minsiz=1<<30;
	FG(x,0);
	vst[G]=1;
	Cal(G,0,1);
	for(int p=e.h[G];p;p=e.next[p])if(!vst[e.to[p]]){
		Cal(e.to[p],e.w[p],-1);
		sum=siz[e.to[p]];
		work(e.to[p]);
	}
}
int main(){
	init();
	work(1);
	printf("%d",ans);
	return 0;
}