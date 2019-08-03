#include<cstdio>
#define ll long long
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)

inline void Swap(ll &a,ll &b) {
    a^=b^=a^=b;
}

inline ll Max(ll a,ll b){
    return a>b?a:b;
}

const ll maxn=100000;
ll mod;

ll sum[(maxn<<2)+5],maxx[(maxn<<2)+5];
void pushup(ll v) {
    sum[v]=(sum[lc(v)]+sum[rc(v)]);
    maxx[v]=Max(maxx[lc(v)],maxx[rc(v)]);
}
void update(ll v,ll l,ll r,ll x,ll add) {
    if(l==r) {
        sum[v]=maxx[v]=add;
        return;
    }
    ll mid=l+r>>1;
    if(x<=mid)update(lc(v),l,mid,x,add);
    else update(rc(v),mid+1,r,x,add);
    pushup(v);
}

ll querysum(ll v,ll l,ll r,ll left,ll right) {
    if(l>=left&&r<=right)return sum[v];
    ll mid=l+r>>1,ans=0;
    if(left<=mid)ans=(ans+querysum(lc(v),l,mid,left,right));
    if(mid<right)ans=(ans+querysum(rc(v),mid+1,r,left,right));
    return ans;
}

ll querymax(ll v,ll l,ll r,ll left,ll right) {
    if(l>=left&&r<=right)return maxx[v];
    ll mid=l+r>>1,ans1=-30005,ans2=-30005;
    if(left<=mid)ans1=querymax(lc(v),l,mid,left,right);
    if(mid<right)ans2=querymax(rc(v),mid+1,r,left,right);
    return Max(ans1,ans2);
}

struct edges {
    ll v[maxn*2+5];
    ll first[maxn+5],next[maxn*2+5];
    ll tot=0;
    void addedge(ll a,ll b) {
        tot++;v[tot]=b;
        next[tot]=first[a];
        first[a]=tot;
    }
} e;

ll fa[maxn+5],dep[maxn+5],size[maxn+5],son[maxn+5];
ll top[maxn+5],rank[maxn+5],id[maxn+5];
ll cnt=0;

void dfs1(ll x) {
    size[x]=1;
    for(ll i=e.first[x]; i; i=e.next[i]) {
        ll y=e.v[i];
        if(fa[x]==y)continue;
        fa[y]=x;
        dep[y]=dep[x]+1;
        dfs1(y);
        size[x]+=size[y];
        if(size[son[x]]<size[y])son[x]=y;
    }
}

void dfs2(ll x,ll tp) {
    top[x]=tp;
    rank[x]=++cnt;
    id[cnt]=x;
    if(son[x])dfs2(son[x],tp);
    for(ll i=e.first[x]; i; i=e.next[i]) {
        ll y=e.v[i];
        if(fa[x]==y||son[x]==y)continue;
        dfs2(y,y);
    }
}

ll n,m;

ll ans1(ll a,ll b) {
    ll ans=0;
    while(top[a]!=top[b]) {
        if(dep[top[a]]<dep[top[b]])Swap(a,b);
        ans+=querysum(1,1,n,rank[top[a]],rank[a]);
        a=fa[top[a]];
    }
    if(dep[a]>dep[b])Swap(a,b);
    ans+=querysum(1,1,n,rank[a],rank[b]);
    return ans;
}

ll ans2(ll a,ll b) {
    ll ans=-30005,ans1;
    while(top[a]!=top[b]) {
        if(dep[top[a]]<dep[top[b]])Swap(a,b);
        ans1=querymax(1,1,n,rank[top[a]],rank[a]);
        ans=Max(ans,ans1);
        a=fa[top[a]];
    }
    if(dep[a]>dep[b])Swap(a,b);
    ans1=querymax(1,1,n,rank[a],rank[b]);
    ans=Max(ans,ans1);
    return ans;
}

void work1(ll a,ll b){
    update(1,1,n,rank[a],b);
}

ll kp[maxn+5];

int main() {
    ll s;
    scanf("%lld",&n);
    for(ll i=1; i<n; i++) {
        ll a,b;scanf("%lld%lld",&a,&b);
        e.addedge(a,b),e.addedge(b,a);
    }
    s=1;
    dep[s]=1;
    dfs1(s);
    dfs2(s,s);
    for(ll i=1; i<=n; i++)scanf("%lld",&kp[i]);
    for(ll i=1; i<=n; i++)update(1,1,n,rank[i],kp[i]);
    scanf("%lld",&m);
    for(ll i=1; i<=m; i++) {
    	char ch=getchar();
    	while(ch!='G'&&ch!='X'&&ch!='U')ch=getchar();
    	char temp=getchar();
    	while(temp!=' ')temp=getchar();
        if(ch=='G'){
            ll a,b;scanf("%lld%lld",&a,&b);
            work1(a,b);
        }
        if(ch=='X'){
            ll a,b;scanf("%lld%lld",&a,&b);
            printf("%lld\n",ans2(a,b));
        }
        if(ch=='U'){
            ll a,b;scanf("%lld%lld",&a,&b);
            printf("%lld\n",ans1(a,b));
        }
    }
    return 0;
}
/*
4
1 2
2 3
4 1
4 2 1 3
12
QMAX 3 4
QMAX 3 3
QMAX 3 2
QMAX 2 3
QSUM 3 4
QSUM 2 1
CHANGE 1 5
QMAX 3 4
CHANGE 3 6
QMAX 3 4
QMAX 2 4
QSUM 3 4

*/
