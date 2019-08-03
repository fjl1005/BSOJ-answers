#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=51061;

const ll maxn=300010;
ll f[maxn],ch[maxn][2],st[maxn],size[maxn],val[maxn],sum[maxn],tagad[maxn],tagmul[maxn];
bool rev[maxn];
inline bool nroot(ll x){return ch[f[x]][1]==x||ch[f[x]][0]==x;}
inline bool chk(ll x){return x==ch[f[x]][1];}
void pushup(ll x){
	size[x]=(size[ch[x][0]]+size[ch[x][1]]+1)%mod;
	sum[x]=(sum[ch[x][0]]+sum[ch[x][1]]+val[x])%mod;
}
void pushrev(ll x){swap(ch[x][0],ch[x][1]);rev[x]^=1;}
void cal(ll x,ll m,ll a){
	if(!x)return;
	val[x]=(val[x]*m+a)%mod;
	sum[x]=(sum[x]*m+a*size[x])%mod;
	tagad[x]=(tagad[x]*m+a)%mod;
	tagmul[x]=(tagmul[x]*m)%mod;
}
void pushdown(ll x){
    if(rev[x]){
        pushrev(ch[x][0]);
        pushrev(ch[x][1]);
        rev[x]=0;
    }
    if(tagmul[x]!=1||tagad[x]!=0){
    	cal(ch[x][0],tagmul[x],tagad[x]);
    	cal(ch[x][1],tagmul[x],tagad[x]);
    	tagmul[x]=1,tagad[x]=0;
    }
}
void rotate(ll &x){
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
    access(x);splay(x);pushrev(x);
}
ll findroot(ll x){
    access(x);splay(x);
    while(ch[x][0])x=ch[x][0];
    return x;
}
void split(ll x,ll y){
    makeroot(x);access(y);splay(y);
}
void link(ll x,ll y){
    makeroot(x);f[x]=y;
}
void cut(ll x,ll y){
    split(x,y);
	f[x]=ch[y][0]=0;
}
void ans(ll x,ll y){
	split(x,y);
	printf("%lld\n",sum[y]%mod);	
}
void add(ll x,ll y,ll c){
	split(x,y);cal(y,1,c);
}
void mul(ll x,ll y,ll c){
	split(x,y);cal(y,c,0);
}
int main() {
//	freopen("t.in","r",stdin);
//	freopen("t.out","w",stdout);
    ll n,m;scanf("%lld",&n);scanf("%lld",&m);
    for(ll i=1;i<=n;i++)size[i]=val[i]=tagmul[i]=1,tagad[i]=0;
    for(ll i=1;i<n;i++){
		ll x,y;scanf("%lld%lld",&x,&y);
		link(x,y);
    }
    while(m--){
        char cs[15];
		ll x,y;scanf("%s%lld%lld",cs,&x,&y);ll u,v;ll c;
        switch(cs[0]){
            case '+':scanf("%lld",&c);add(x,y,c);break;
            case '-':scanf("%lld%lld",&u,&v);cut(x,y);link(u,v);break;
            case '*':scanf("%lld",&c);mul(x,y,c);break;
            case '/':ans(x,y);break;
        }
    }
    return 0;
}
/*
10 10
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
/ 1 10
*/