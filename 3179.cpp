#include<bits/stdc++.h>
using namespace std;
#define Inc(i,L,R) for(register int i=(L);i<=(R);++i)
#define Red(j,R,L) for(register int j=(R);j>=(L);--j)
#define lc(v) ch[v][0]
#define rc(v) ch[v][1]
#define inf 0x7fffffff
const int N = 2e5+10;
int n,m,a[N/2];
struct Splay{
	int k[N],Max[N],siz[N];
	int rt,cnt,p[N],ch[N][2];
	inline void pushup(int x){
		siz[x]=siz[lc(x)]+siz[rc(x)]+1;
		Max[x]=max(k[x],max(Max[lc(x)],Max[rc(x)]));
	}
	inline int build(int L,int r){
		if(L>r)return 0;
		int x=++cnt,Mid=L+r>>1;
		k[x]=Max[x]=a[Mid];
		siz[x]=1;
		lc(x)=build(L,Mid-1);
		rc(x)=build(Mid+1,r);
		if(lc(x))p[lc(x)]=x;
		if(rc(x))p[rc(x)]=x;
		pushup(x);
		return x;
	}
	inline void rot(int x){
		int f=p[x],gf=p[f],type=rc(f)==x,son=ch[x][!type];
		ch[p[son]=f][type]=son,pushup(f);
		ch[p[f]=x][!type]=f,pushup(x);
		ch[p[x]=gf][rc(gf)==f]=x;
	}
	inline void splay(int x,int goal){
		while(p[x]^goal){
			if((p[p[x]]^goal)&&((rc(p[p[x]])==p[x])==(rc(p[x])==x)))rot(p[x]);
			rot(x);
		}
		if(!goal)rt=x;
	}
	inline int find(int Size){
		int x=rt;
		while(1){
			if(siz[lc(x)]+1==Size)break;
			if(Size>siz[lc(x)]+1)Size-=siz[lc(x)]+1,x=rc(x);
			else x=lc(x);
		}
		return x;
	}
	inline void remove(int kp){
		int L=find(kp-1),r=find(kp+1);
		splay(L,0),splay(r,rt);
		lc(r)=0;
		pushup(r),pushup(L);
	}
	inline void insert(int kp,int v){
		int L=find(kp-1),r=find(kp);
		splay(L,0),splay(r,rt);
		siz[++cnt]=1;
		k[cnt]=Max[cnt]=v;
		p[lc(r)=cnt]=r;
		pushup(cnt),pushup(r),pushup(L);
	}
	inline void update(int a,int b,bool opt){
		int New,Tmpk;
		if(opt==0){
			int ap=find(a),bp=find(a+b+1);
			splay(ap,0),splay(bp,rt);
			printf("%d\n",Max[lc(bp)]);
			New=a+b;
		}else {
			int ap=find(a-b-1),bp=find(a);
			splay(ap,0),splay(bp,rt);
			printf("%d\n",Max[lc(bp)]);
			New=a-b;
		}
		Tmpk=k[find(a)];
		remove(a);
		insert(New,Tmpk);
	}
}sp;
inline void init(){
	scanf("%d%d",&n,&m);
	a[1]=-inf;
	Inc(i,2,n+1)scanf("%d",&a[i]);
	a[n+2]=-inf;
	sp.rt=sp.build(1,n+2);
}
inline void solv(){
	Inc(i,1,m){
		long long a,b;
		scanf("%lld",&a);char c=getchar();while(c!='D'&&c!='L')c=getchar();scanf("%lld",&b);
		if(c=='D')sp.update(a+1,b,0);
		else sp.update(a+1,b,1);
	}
}
int main(){
	init();
	solv();
	return 0;
}