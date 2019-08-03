#include<bits/stdc++.h>
using namespace std;
#define ll int
namespace Splay{
    const ll inf=1ll<<31-1;
    const ll maxn=800010;
    ll root=0,decnt=0;//root表示splay的根节点 decnt代表新建节点编号 
    ll ch[maxn][2],size[maxn],cnt[maxn],val[maxn],prt[maxn];
    //ch[v][0]表示v的左儿子 ch[v][1]表示v的右儿子 prt[v]表示v的父亲 
    //val[v]表示v的值 size[v]表示以v为根节点的子树的节点总数 cnt[v]表示值为val[v]的点的个数
    //rev[v]==1时代表要区间翻转 rev[v]==0时表示不需要区间翻转 
    ll chk(ll v){return ch[prt[v]][1]==v;}
    void cl(ll v){ch[v][0]=ch[v][1]=size[v]=cnt[v]=val[v]=prt[v]=0;}
    void swap(ll &a,ll &b){a^=b^=a^=b;}
    void pushup(ll v){size[v]=size[ch[v][0]]+size[ch[v][1]]+cnt[v];}

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
        pushup(cur);
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
        if(cnt[del]>1){cnt[del]--;size[del]--;}
		else ch[nxt][0]=0,cl(del);
        pushup(nxt);pushup(lst);
    }
    void reverse(ll l,ll r){
        ll x=kth(l),y=kth(r+2);
        splay(x),splay(y,x);
    }
    void print(ll v){
        if(!v)return;
        print(ch[v][0]);
        if(val[v]!=inf&&val[v]!=-inf)for(ll i=1;i<=cnt[v];i++)printf("%lld ",val[v]);
        print(ch[v][1]);
    }
}
using namespace Splay;
ll n;
ll ans=0;
int main(){
//	freopen("p.in","r",stdin);
//	freopen("p.out","w",stdout);
    insert(inf);
    insert(-inf);
    ll flag=-1;
    scanf("%d",&n);
    for(ll i=1;i<=n;i++){
    	ll a,b;scanf("%d%d",&a,&b);
    	if(a==0){
    		if(flag!=1)insert(b),flag=0;
    		else{
    			insert(b);find(b);
				if(cnt[root]>1){remove(b);continue;}
				ll x=pre(b),y=succ(b);
				ll minn=inf,ai=0;
				if(abs(val[x])!=inf)if(abs(val[x]-b)<minn)minn=abs(val[x]-b),ai=x;
				if(abs(val[y])!=inf)if(abs(val[y]-b)<minn)minn=abs(val[y]-b),ai=y;
				if(ai)ans+=minn,remove(val[ai]);remove(b);ans%=1000000;
				if(size[root]<=2)flag=-1;
			}
		}
		if(a==1){
    		if(flag!=0)insert(b),flag=1;
    		else{
    			insert(b);find(b);
				if(cnt[root]>1){remove(b);continue;}
				ll x=pre(b),y=succ(b);
				ll minn=inf,ai=0;
				if(abs(val[x])!=inf)if(abs(val[x]-b)<minn)minn=abs(val[x]-b),ai=x;
				if(abs(val[y])!=inf)if(abs(val[y]-b)<minn)minn=abs(val[y]-b),ai=y;
				if(ai)ans+=minn,remove(val[ai]);remove(b);ans%=1000000;
				if(size[root]<=2)flag=-1;
			}
		}
	}
	printf("%d",ans%1000000);
    return 0;
}
/*
1000
0 27867396
0 98749190
0 96465999
0 65082911
0 65103952
0 25848695
0 39019295
0 96958260
0 39422477
0 79079169
0 34392589
0 66399630
0 97116166
0 41557015
0 15078987
0 42401827
0 98563873
0 11841316
0 61909938
0 66359479
0 75891260
0 44382650
0 14885449
0 20512408
0 46855074
0 96140018
0 40137423
0 2919124
0 84880556
0 79565909
0 53146130
0 8348450
0 45521960
0 21759478
0 98289786
0 15709264
0 49026211
0 29897856
0 84517280
0 81508373
0 19179679
0 62945586
0 77404003
0 39746506
0 78498084
0 9532180
0 47340822
0 7892439
0 99519521
0 72197800
0 74066163
0 99245239
0 12480615
0 57747071
0 7381229
0 41444635
0 69165796
0 73981014
0 84188339
0 1309513
0 62969700
0 32627100
0 1642395
0 15864540
0 5342703
0 58477438
0 46745468
0 29674908
0 58379564
0 4875085
0 82014515
0 38399206
0 23661211
0 75348472
0 87522221
0 38540414
0 87429638
0 51543973
0 59100958
0 83585029
0 21865933
0 27456580
0 62889882
0 46230305
0 42821431
0 49798715
0 45975141
0 87009628
0 23571995
0 64677165
0 3503221
0 28996011
0 65035410
0 70598137
0 1857405
0 38993715
0 22031919
0 77560444
0 58137368
0 14737997
1 86027870
*/