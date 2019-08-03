#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
const ll maxn=100000;

ll v[maxn*2+5],w[maxn*2+5];
ll first[maxn+5],next[maxn*2+5];
ll tot=0;
void addedge(ll a,ll b,ll c) {
    tot++;v[tot]=b,w[tot]=c;
    next[tot]=first[a];
    first[a]=tot;
}

ll maxx[(maxn<<2)+5]={0};
void pushup(ll v) {maxx[v]=max(maxx[lc(v)],maxx[rc(v)]);}
void update(ll v,ll l,ll r,ll x,ll add) {
    if(l==x&&r==x) {maxx[v]=add;return;}
    ll mid=l+r>>1;
	if(x<=mid)update(lc(v),l,mid,x,add);
    if(mid<x)update(rc(v),mid+1,r,x,add);
    pushup(v);
}
ll query(ll v,ll l,ll r,ll left,ll right) {
    if(left<=l&&r<=right)return maxx[v];
    ll mid=l+r>>1,a=0,b=0;
    if(left<=mid)a=query(lc(v),l,mid,left,right);
    if(mid<right)b=query(rc(v),mid+1,r,left,right);
    return max(a,b);
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
    if(u==v)return -1;
    ll f1=top[u],f2=top[v],ans=-1;
    while(f1!=f2){
        if(dep[f1]<dep[f2])swap(f1,f2),swap(u,v);
        ans=max(ans,query(1,1,n,rank[f1],rank[u]));
        u=fa[f1];f1=top[u];
    }
    if(u==v)return ans;
    if(dep[u]>dep[v])swap(u,v);
    return max(ans,query(1,1,n,rank[son[u]],rank[v]));
}

ll s[maxn*2],t[maxn*2],k[maxn*2];

int main() { 
    scanf("%lld%lld",&n,&m);
    for(ll i=1; i<n; i++) {
        ll a,b,c;scanf("%lld%lld%lld",&a,&b,&c);
        addedge(a,b,c),addedge(b,a,c);
        s[i]=a,t[i]=b,k[i]=c;
    }
    dep[1]=1;
    dfs1(1);
    dfs2(1,1);
//    for(ll i=1;i<=n;i++)printf("%lld ",son[i]);puts("");
//    for(ll i=1;i<=n;i++)printf("%lld ",[i]);puts("");
//    for(ll i=1;i<=n;i++)printf("%lld ",rank[i]);puts("");
//    for(ll i=1;i<=n;i++)printf("%lld ", top[i]);puts("");
    for(ll i=1;i<n;i++){
    	if(dep[s[i]]<dep[t[i]])swap(s[i],t[i]);
    	update(1,1,n,rank[s[i]],k[i]);
    }
    for(ll i=1; i<=m; i++) {
        ll op,a,b;scanf("%lld%lld%lld",&op,&a,&b);
        if(op==0)update(1,1,n,rank[s[a]],b); 
        if(op==1)printf("%lld\n",ans(a,b));
    }
    return 0;
}
