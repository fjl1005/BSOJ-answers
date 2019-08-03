#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m;
const ll maxn=300010;
ll f[maxn],ch[maxn][2],st[maxn],sum[maxn],value[maxn];
bool rev[maxn];
inline bool nroot(ll x){return ch[f[x]][1]==x||ch[f[x]][0]==x;}
inline bool chk(ll x){return x==ch[f[x]][1];}
void pushrev(ll x){swap(ch[x][0],ch[x][1]);rev[x]^=1;}
void pushdown(ll x){
    if(rev[x]){
        if(ch[x][0])pushrev(ch[x][0]);
        if(ch[x][1])pushrev(ch[x][1]);
        rev[x]=0;
    }
}
void pushup(ll x){sum[x]=sum[ch[x][0]]+sum[ch[x][1]]+1;}
void rotate(ll x){
    ll y=f[x],z=f[y],k=chk(x),w=ch[x][k^1];
    if(nroot(y))ch[z][chk(y)]=x;
    ch[x][k^1]=y,ch[y][k]=w;
    if(w)f[w]=y;
    f[y]=x,f[x]=z;
    pushup(y);pushup(x);
}
void splay(ll x){
    ll y=x,top=0;
    st[++top]=y;
    while(nroot(y))st[++top]=y=f[y];
    while(top)pushdown(st[top--]);
    while(nroot(x)){
        y=f[x];
        if(nroot(y)){
            if(chk(x)==chk(y))rotate(y);
            else rotate(x);
        }
        rotate(x);
    }
    pushup(x);
}
void access(ll x){for(ll cur=0;x;x=f[cur=x])splay(x),ch[x][1]=cur,pushup(x);}
void makeroot(ll x){
    access(x);splay(x);
    pushrev(x);
}
ll findroot(ll x){
    access(x);splay(x);
    while(ch[x][0])pushdown(x),x=ch[x][0];
    return x;
}
void split(ll x,ll y){
    makeroot(x);access(y);splay(y);
}
void link(ll x,ll y){
    makeroot(x);
    if(findroot(y)!=x)f[x]=y;
    splay(y);
}
void cut(ll x,ll y){
    makeroot(x);access(y);splay(y);
	f[x]=ch[y][0]=0;
}
ll ans(ll x,ll y){
	makeroot(x);access(y);splay(y);
	return sum[y]-1;
}
ll p[maxn];
int main() {
	scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
		scanf("%lld",&p[i]);
		link(i,min(i+p[i],n+1));
	}
    scanf("%lld",&m);
    while(m--){
		ll i,j,k;scanf("%lld%lld",&i,&j);j++;
        switch(i){
            case 1:printf("%lld\n",ans(n+1,j));break;
            case 2:scanf("%lld",&k);cut(j,min(j+p[j],n+1));p[j]=k;link(j,min(j+p[j],n+1));break;
        }
//	for(ll x=1;x<=n*2;x++)printf("%lld ",sum[x]);puts("");
    }
    return 0;
}
