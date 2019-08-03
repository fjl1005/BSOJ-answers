#include <cstdio>
#include <algorithm>
#include <cmath>
#define N 100010
using namespace std;

struct info{int to,nex;}e[N*2];
int n,m,A[N],rank[N],T[N],ls[N*20],rs[N*20],sum[N*20],tot,cnt,preAns;
int _log,fa[N],head[N],f[N][20],dep[N];

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

void Link(int u,int v){
    e[++tot].nex=head[u];
    e[tot].to=v;
    head[u]=tot;
}

void update(int last,int p,int l,int r,int &rt){
    rt=++tot;
    ls[rt]=ls[last],rs[rt]=rs[last],sum[rt]=sum[last]+1;
    if(l==r) return;
    int m=(l+r)>>1;
    if(p<=m) update(ls[last],p,l,m,ls[rt]);
    else update(rs[last],p,m+1,r,rs[rt]);
}

void dfs(int u,int fa){
    update(T[fa],A[u],1,cnt,T[u]);
    for(int i=1;i<=_log;++i)
        f[u][i]=f[f[u][i-1]][i-1];
    for(int i=head[u];i;i=e[i].nex){
        int v=e[i].to;
        if(v==fa) continue;
        dep[v]=dep[u]+1;
        f[v][0]=u;
        dfs(v,u);
    }
}

int LCA(int u,int v){
    if(dep[u]>dep[v]) swap(u,v);
    int d=dep[v]-dep[u];
    
    for(int i=0;i<=_log;++i)
        if(d&(1<<i)) v=f[v][i];
    if(u==v) return v;
    
    for(int i=_log;i>=0;--i)
        if(f[u][i]!=f[v][i]){
            u=f[u][i];
            v=f[v][i];
        }
    return f[u][0];
}

int query(int l,int r,int x,int y,int a,int b,int k){
    if(l==r) return l;
    int m=(l+r)>>1,d=sum[ls[x]]-sum[ls[b]]+sum[ls[y]]-sum[ls[a]];
    if(d>=k) return query(l,m,ls[x],ls[y],ls[a],ls[b],k);
    else return query(m+1,r,rs[x],rs[y],rs[a],rs[b],k-d);
}

int main(){
    n=read(),m=read();
    _log=log(n)/log(2);
    for(int i=1;i<=n;++i) A[i]=rank[i]=read();
    sort(rank+1,rank+n+1);
    cnt=unique(rank+1,rank+n+1)-(rank+1);
    for(int i=1;i<=n;++i) A[i]=lower_bound(rank+1,rank+cnt+1,A[i])-rank;
    for(int i=1;i<n;++i){
        int u=read(),v=read();
        Link(u,v);Link(v,u);
    }
    tot=0;
    dfs(1,0);
    while(m--){
        int u=read()^preAns,v=read(),k=read();
        int lca=LCA(u,v);
        printf("%d",preAns=rank[query(1,cnt,T[u],T[v],T[lca],T[f[lca][0]],k)]);
        if(m>0) printf("\n");
    }
    return 0;
}