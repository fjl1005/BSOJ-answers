#include<cstdio>
#define ll long long
namespace splay{
    const ll inf=1ll<<30;
    const ll maxn=200010;
    ll root=0,decnt=0;//root表示splay的根节点 decnt代表新建节点编号 
    ll ch[maxn][2],size[maxn],cnt[maxn],val[maxn],prt[maxn],rev[maxn];
    //ch[v][0]表示v的左儿子 ch[v][1]表示v的右儿子 prt[v]表示v的父亲 
    //val[v]表示v的值 size[v]表示以v为根节点的子树的节点总数 cnt[v]表示值为val[v]的点的个数
    //rev[v]==1时代表要区间翻转 rev[v]==0时表示不需要区间翻转 
    ll chk(ll v){return ch[prt[v]][1]==v;}
    void swap(ll &a,ll &b){a^=b^=a^=b;}
    void pushup(ll v){size[v]=size[ch[v][0]]+size[ch[v][1]]+cnt[v];}
    void pushdown(ll v){
        if(rev[v]){
            swap(ch[v][0],ch[v][1]);
            rev[ch[v][0]]^=1,rev[ch[v][1]]^=1;
            rev[v]=0;
        }
    }
    void rotate(ll v){
        ll y=prt[v],z=prt[y],d=chk(v),k=ch[v][d^1];
        ch[y][d]=k;prt[k]=y;
        ch[z][chk(y)]=v;prt[v]=z;
        ch[v][d^1]=y;prt[y]=v;
        pushup(y),pushup(v);
    }
    void splay(ll cur,ll v=0){
        while(prt[cur]!=v){
            ll pr=prt[cur];
            if(prt[pr]!=v){
                if(chk(cur)==chk(pr))rotate(pr);
                else rotate(cur);
            }
            rotate(cur);
        }
        if(!v)root=cur;
    }
    void insert(ll x){
        ll cur=root,p=0;
        while(cur&&x!=val[cur])p=cur,cur=ch[cur][x>val[cur]];
        if(cur)cnt[cur]++;
        else{
            cur=++decnt;
            if(p)ch[p][x>val[p]]=cur;
            ch[cur][0]=ch[cur][1]=0;
            val[cur]=x;prt[cur]=p;
            size[cur]=cnt[cur]=1;
        }
        splay(cur);
    }
    void find(ll x){
        ll cur=root;
        while(ch[cur][x>val[cur]]&&x!=val[cur])cur=ch[cur][x>val[cur]];
        splay(cur);
    }
    ll rank(ll x){
        find(x);return size[ch[root][0]];
        //本来应该是返回 size[ch[root][0]]+1但为了避免溢出，我先insert了inf和-inf，所以排名就应该-1 
    }
    ll kth(ll k){
        ll cur=root;
        while(true){
            pushdown(cur);
            if(ch[cur][0]&&size[ch[cur][0]]>=k)cur=ch[cur][0];
            else if(ch[cur][1]&&size[ch[cur][0]]+cnt[cur]<k)k-=size[ch[cur][0]]+cnt[cur],cur=ch[cur][1];
            else return cur;
        }
        return cur;
    }
    ll pre(ll x){
        find(x);
        if(val[root]<x)return root;//特判一下，防止出现查找不存在的数的情况 
        ll cur=ch[root][0];
        while(ch[cur][1])cur=ch[cur][1];
        return cur;
    }
    ll succ(ll x){
        find(x);
        if(val[root]>x)return root;//特判一下，防止出现查找不存在的数的情况
        ll cur=ch[root][1];
        while(ch[cur][0])cur=ch[cur][0];
        return cur;
    }
    void remove(ll x){
        ll lst=pre(x),nxt=succ(x);
        splay(lst),splay(nxt,lst);
        ll del=ch[nxt][0];
        if(cnt[del]>1){
            cnt[del]--;splay(del);
        }else ch[nxt][0]=0;
    }
    void reverse(ll l,ll r){
        ll x=kth(l),y=kth(r+2);
        splay(x),splay(y,x);
        rev[ch[y][0]]^=1;
    }
    void print(ll v){
        if(!v)return;
        pushdown(v);
        print(ch[v][0]);
        if(val[v]!=inf&&val[v]!=-inf)for(ll i=1;i<=cnt[v];i++)printf("%lld ",val[v]);
        print(ch[v][1]);
    }
}
using namespace splay;
ll n;
int main(){
    scanf("%lld",&n);
    insert(inf);
    insert(-inf);
    while(n--){
        ll opt,x;
        scanf("%lld%lld",&opt,&x);
        switch(opt){
            case 1:{insert(x);break;}
            case 2:{remove(x);break;}
            case 3:{printf("%lld\n",rank(x));break;}
            case 4:{printf("%lld\n",val[kth(x+1)]);break;}
            case 5:{printf("%lld\n",val[pre(x)]);break;}
            case 6:{printf("%lld\n",val[succ(x)]);break;}
        }
    }
    return 0;
}