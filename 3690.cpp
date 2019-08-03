#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
const ll maxn=200000;

ll v[maxn*2+5],w[maxn*2+5];
ll first[maxn+5],next[maxn*2+5];
ll tot=0;
void addedge(ll a,ll b) {
    tot++;v[tot]=b;
    next[tot]=first[a];
    first[a]=tot;
}

ll maxx[(maxn<<2)+5]={0};
ll sum[(maxn<<2)+5],tag[(maxn<<2)+5];
void pushup(ll v) {sum[v]=(sum[lc(v)]+sum[rc(v)]);}
void pushdown(ll v,ll l,ll r) {
    if(tag[v]) {
        ll mid=l+r>>1;
        tag[lc(v)]=(tag[lc(v)]+tag[v]);
        tag[rc(v)]=(tag[rc(v)]+tag[v]);
        sum[lc(v)]=(sum[lc(v)]+tag[v]*(mid-l+1));
        sum[rc(v)]=(sum[rc(v)]+tag[v]*(r-mid));
        tag[v]=0;
    }
}
void update(ll v,ll l,ll r,ll left,ll right,ll add) {
    if(l>=left&&r<=right) {
        sum[v]=(sum[v]+add*(r-l+1));
        tag[v]=(tag[v]+add);
        return;
    }
    pushdown(v,l,r);
    ll mid=l+r>>1;
    if(left<=mid)update(lc(v),l,mid,left,right,add);
    if(mid<right)update(rc(v),mid+1,r,left,right,add);
    pushup(v);
}
ll query(ll v,ll l,ll r,ll left,ll right) {
    if(l>=left&&r<=right)return sum[v];
    ll mid=l+r>>1,ans=0;
    pushdown(v,l,r);
    if(left<=mid)ans=(ans+query(lc(v),l,mid,left,right));
    if(mid<right)ans=(ans+query(rc(v),mid+1,r,left,right));
    return ans;
}

ll fa[maxn+5],dep[maxn+5],size[maxn+5],son[maxn+5];
ll top[maxn+5],rank[maxn+5],id[maxn+5];
ll cnt=0;

void dfs1(ll x) {
    size[x]=1;
    for(ll i=first[x]; i; i=next[i]) {
        ll y=v[i];
        if(fa[x]==y)continue;
        fa[y]=x;
        dep[y]=dep[x]+1;
        dfs1(y);
        size[x]+=size[y];
        if(size[son[x]]<size[y])son[x]=y;
    }
}

void dfs2(ll x,ll tp) {
    top[x]=tp;rank[x]=++cnt;id[cnt]=x;
    if(son[x])dfs2(son[x],tp);
    for(ll i=first[x]; i; i=next[i]) {
        ll y=v[i];
        if(fa[x]==y||son[x]==y)continue;
        dfs2(y,y);
    }
}

ll n,m;

ll ans(ll u,ll v){
    if(u==v)return 0;
    ll f1=top[u],f2=top[v],ans=0;
    while(f1!=f2){
        if(dep[f1]<dep[f2])swap(f1,f2),swap(u,v);
//        printf("%lld\n",query(1,1,n,rank[f1],rank[u]));
        ans=(ans+query(1,1,n,rank[f1],rank[u]));
        u=fa[f1];f1=top[u];
    }
    if(u==v)return ans;
    if(dep[u]>dep[v])swap(u,v);
    return (ans+query(1,1,n,rank[son[u]],rank[v]));
}

void work(ll u,ll v){
    ll f1=top[u],f2=top[v];
    while(f1!=f2){
        if(dep[f1]<dep[f2])swap(f1,f2),swap(u,v);
        update(1,1,n,rank[f1],rank[u],1);
        u=fa[f1];f1=top[u];
    }
    if(u==v)return;
    if(dep[u]>dep[v])swap(u,v);
    update(1,1,n,rank[son[u]],rank[v],1);
}

//ll ii[maxn],io[maxn];
int main() { 
    scanf("%lld%lld",&n,&m);
    for(ll i=1; i<n; i++) {
        ll a,b;scanf("%lld%lld",&a,&b);
        addedge(a,b),addedge(b,a);
    }
    dep[1]=1;
    dfs1(1);
    dfs2(1,1);
//    for(ll i=1;i<=n;i++)printf("%lld ",rank[i]);
    for(ll i=1; i<=m; i++) {
        char ch=getchar();while(ch!='P'&&ch!='Q')ch=getchar();ll a,b;scanf("%lld%lld",&a,&b);
        if(dep[a]<dep[b])swap(a,b);
        if(ch=='P')work(a,b);
        if(ch=='Q')printf("%lld\n",ans(a,b));
        
//        for(ll i=1;i<=7;i++)printf("%lld ",tag[i]);puts("");
//        for(ll i=1;i<=7;i++)printf("%lld ",sum[i]);puts("");
    }
    return 0;
}
/*
5 5
1 2
2 3
3 4
4 5
P 1 5
P 2 3
Q 2 4
P 2 4
Q 1 3
*/

