#include<cstdio>
#define ll long long
const ll maxn=1000010;
inline void Swap(ll &a,ll &b){a^=b^=a^=b;}
ll val[maxn],lc[maxn],rc[maxn];
ll f[maxn];
ll n,m;
ll gf(ll x){
    return f[x]<0?x:gf(f[x]);
}
ll merge(ll a,ll b){
    if(!a||!b)return a+b;
    if(val[a]>val[b])Swap(a,b);
    rc[a]=merge(rc[a],b);
    f[rc[a]]=a;
    Swap(lc[a],rc[a]);
    return a;
}
void hell(ll a,ll b){
    if(val[a]<0||val[b]<0)return;
    ll fa=gf(a),fb=gf(b);
    if(fa==fb)return;
    merge(fa,fb);
}
void pop(ll a){
    if(val[a]<0)return;
    val[a]=f[lc[a]]=f[rc[a]]=-1;
    hell(lc[a],rc[a]);
}
void query(ll a){
    if(val[a]<0){printf("0\n");return;}
    ll rt=gf(a);
    printf("%lld\n",val[rt]);
    pop(rt);
}

int main(){
//	freopen("pop.in","r",stdin);
//	freopen("pop.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)scanf("%lld",&val[i]),f[i]=-1;
    scanf("%lld",&m);
    while(m--){
        char opt=getchar();
        while(opt!='M'&&opt!='K')opt=getchar();
        if(opt=='M'){
            ll x,y;scanf("%lld%lld",&x,&y);
            hell(x,y);
        }else{
            ll x;scanf("%lld",&x);query(x);
        }
    }
    return 0;
}