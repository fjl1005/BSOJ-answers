#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=200010;
int ch[maxn][2],fa[maxn],rev[maxn],sum[maxn],col[maxn],lcol[maxn],rcol[maxn];
int Laxt[maxn],Next[maxn<<1],To[maxn<<1],lazy[maxn],cnt;
void reverse(int x){ if(!x) return ; swap(ch[x][0],ch[x][1]);swap(lcol[x],rcol[x]); rev[x]^=1;} //一定要记得把lcol和rcol给swap了...
void change(int x,int y){ col[x]=lcol[x]=rcol[x]=y; sum[x]=1; lazy[x]=y;}
void pushdown(int x)
{
    if(rev[x]){
        reverse(ch[x][0]); reverse(ch[x][1]); rev[x]=0;
    }
    if(lazy[x]){
        change(ch[x][0],lazy[x]);
        change(ch[x][1],lazy[x]);
        lazy[x]=0;
    }
}
void pushup(int x)
{
    lcol[x]=ch[x][0]?lcol[ch[x][0]]:col[x];
    rcol[x]=ch[x][1]?rcol[ch[x][1]]:col[x];
    sum[x]=1;
    if(ch[x][0]) sum[x]+=sum[ch[x][0]]-(col[x]==rcol[ch[x][0]]);
    if(ch[x][1]) sum[x]+=sum[ch[x][1]]-(col[x]==lcol[ch[x][1]]);
}
void add(int u,int v){ Next[++cnt]=Laxt[u]; Laxt[u]=cnt; To[cnt]=v; }
void dfs(int u,int f)
{
    fa[u]=f; for(int i=Laxt[u];i;i=Next[i]) if(To[i]!=f) dfs(To[i],u);
}
int get(int x){ return ch[fa[x]][1]==x;}
int isroot(int x){ return ch[fa[x]][1]!=x&&ch[fa[x]][0]!=x;}
void rotate(int x)
{
    int old=fa[x],fold=fa[old],opt=get(x);
    if(!isroot(old)) ch[fold][get(old)]=x;
    fa[x]=fold; fa[old]=x; fa[ch[x][opt^1]]=old;
    ch[old][opt]=ch[x][opt^1]; ch[x][opt^1]=old;
    pushup(old); //x最后一次性pushup，不必重复updatex
}
void P(int x){ if(!isroot(x)) P(fa[x]); pushdown(x);}
void splay(int x)
{
    P(x); for(int f;!isroot(x);rotate(x)){
        if(!isroot(f=fa[x])) rotate(get(x)==get(f)?f:x);
    } 
    pushup(x);
}
void access(int x)
{
    for(int y=0;x;y=x,x=fa[x]){
        splay(x); ch[x][1]=y; pushup(x);//!要的
    }
}
void makeroot(int x) { access(x); splay(x); reverse(x);}
int main()
{
    int N,M,u,v,c; char opt[4];
    scanf("%d%d",&N,&M);
    rep(i,1,N) scanf("%d",&col[i]),change(i,col[i]);
    rep(i,1,N-1){
        scanf("%d%d",&u,&v);
        add(u,v); add(v,u);
    }
    dfs(1,0);
    while(M--){
        scanf("%s",opt+1);
        if(opt[1]=='Q'){
            scanf("%d%d",&u,&v);
            makeroot(u); access(v); splay(v);
            printf("%d\n",sum[v]);
        }
        else {
            scanf("%d%d%d",&u,&v,&c);
            makeroot(u); access(v); splay(v);
            change(v,c);
        }
    }
    return 0;
}