#include<cstdio>
#define ll long long
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)

inline void Swap(ll &a,ll &b) {
    a^=b^=a^=b;
}

const ll maxn=100000;

ll sum[maxn<<2][2];
bool tag[maxn<<2][2];
void pushup(ll v) {
	sum[v][0]=sum[lc(v)][0]+sum[rc(v)][0];
    sum[v][1]=sum[lc(v)][1]+sum[rc(v)][1];
}
void pushdown(ll v,ll l,ll r) {
	ll mid=l+r>>1;
	for(ll i=0;i<=1;i++)
		if(tag[v][i]) {
			tag[v][i]=tag[v][i^1]=0;
			tag[lc(v)][i]=tag[rc(v)][i]=1;
			tag[lc(v)][i^1]=tag[rc(v)][i^1]=0;
			sum[lc(v)][i]=mid-l+1,sum[lc(v)][i^1]=0;
			sum[rc(v)][i]=r-mid,sum[rc(v)][i^1]=0;
		}
	
}
void update(ll v,ll l,ll r,ll left,ll right,bool set) {
    if(l>=left&&r<=right) {
    	sum[v][set^1]=tag[v][set^1]=0;
        sum[v][set]=r-l+1;
        tag[v][set]=1;
        return;
    }
    pushdown(v,l,r);
    ll mid=l+r>>1;
    if(left<=mid)update(lc(v),l,mid,left,right,set);
    if(mid<right)update(rc(v),mid+1,r,left,right,set);
    pushup(v);
}
ll query(ll v,ll l,ll r,ll left,ll right,bool set) {
    if(l>=left&&r<=right)return sum[v][set];
    ll mid=l+r>>1,ans=0;
    pushdown(v,l,r);
    if(left<=mid)ans+=query(lc(v),l,mid,left,right,set);
    if(mid<right)ans+=query(rc(v),mid+1,r,left,right,set);
    return ans;
}

struct edges {
    ll v[maxn*2+5];
    ll first[maxn+5],next[maxn*2+5];
    ll tot=0;
    void addedge(ll a,ll b) {
        tot++;
        v[tot]=b;
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

ll ans1(ll a) {
    ll ans=0,b=1;
    while(top[a]!=top[b]) {
        if(dep[top[a]]<dep[top[b]])Swap(a,b);
        ans+=query(1,1,n,rank[top[a]],rank[a],0);
        a=fa[top[a]];
    }
    if(dep[a]>dep[b])Swap(a,b);
    ans+=query(1,1,n,rank[a],rank[b],0);
    return ans;
}

ll ans2(ll a){
    return query(1,1,n,rank[a],rank[a]+size[a]-1,1);
}

void work1(ll a){
	ll b=1;
    while(top[a]!=top[b]) {
        if(dep[top[a]]<dep[top[b]])Swap(a,b);
        update(1,1,n,rank[top[a]],rank[a],1);
        a=fa[top[a]];
    }
    if(dep[a]>dep[b])Swap(a,b);
    update(1,1,n,rank[a],rank[b],1);
}

void work2(ll a){
    update(1,1,n,rank[a],rank[a]+size[a]-1,0);
}

ll kp[maxn+5];

int main() {
    ll s;
    scanf("%lld",&n);
    for(ll i=2; i<=n; i++)scanf("%lld",&kp[i]),++kp[i];
    for(ll i=2; i<=n; i++)e.addedge(i,kp[i]),e.addedge(kp[i],i);
    s=1;
    dep[s]=1;
    dfs1(s);
    dfs2(s,s);
    
    for(ll i=1; i<=n; i++)update(1,1,n,rank[i],rank[i],0);
    scanf("%lld",&m);
    for(ll i=1; i<=m; i++) {
        char ch=getchar();
        while(ch!='i'&&ch!='u')ch=getchar();
        char temp=getchar();
        while(temp!=' ')temp=getchar();
        ll op;scanf("%lld",&op);op++;
        
        if(ch=='i'){
        	printf("%lld\n",ans1(op));
            work1(op);
        }
        if(ch=='u'){
        	printf("%lld\n",ans2(op));
        	work2(op);
		}
    }
    return 0;
}
