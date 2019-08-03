#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll maxn=300010;
ll f[maxn],ch[maxn][2],st[maxn],sum[maxn],value[maxn];
bool rev[maxn];
inline bool nroot(ll x){return ch[f[x]][1]==x||ch[f[x]][0]==x;}
inline bool chk(ll x){return x==ch[f[x]][1];}
void pushup(ll x){sum[x]=sum[ch[x][0]]^sum[ch[x][1]]^value[x];}
void pushrev(ll x){swap(ch[x][0],ch[x][1]);rev[x]^=1;}
void pushdown(ll x){
    if(rev[x]){
        pushrev(ch[x][0]);
        pushrev(ch[x][1]);
        rev[x]=0;
    }
}
void rotate(ll x){
    ll y=f[x],z=f[y],k=chk(x),w=ch[x][k^1];
    if(nroot(y))ch[z][chk(y)]=x;
    ch[x][k^1]=y,ch[y][k]=w;
    if(w)f[w]=y;
    f[y]=x,f[x]=z;
    pushup(y);
}
void splay(ll x){
    ll y=x,z=0;
    st[++z]=y;
    while(nroot(y))st[++z]=y=f[y];
    while(z)pushdown(st[z--]);
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
}
void cut(ll x,ll y){
    makeroot(x);
    if(findroot(y)==x&&f[x]==y&&!ch[x][1]){
        f[x]=ch[y][0]=0;
        pushup(y);
    }
}
int main() {
    ll n,m;scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)scanf("%lld",&value[i]);
    while(m--){
        char cs[15];
		ll x,y;scanf("%s%lld%lld",cs,&x,&y);
        switch(cs[0]){
            case 'Q':if(findroot(x)==findroot(y))puts("Yes");else puts("No");break;
            case 'C':link(x,y);break;
            case 'D':cut(x,y);break;
        }
    }
    return 0;
}
