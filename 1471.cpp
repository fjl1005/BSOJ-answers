#include<bits/stdc++.h>
using namespace std;
#define ll long long
namespace splay{
    const ll inf=1ll<<30;
    const ll maxn=1000010;
    ll root=0,decnt=0;//root±íÊ¾splayµÄ¸ù½Úµã decnt´ú±íÐÂ½¨½Úµã±àºÅ 
    ll ch[maxn][2],size[maxn],cnt[maxn],val[maxn],prt[maxn],rev[maxn];
    //ch[v][0]±íÊ¾vµÄ×ó¶ù×Ó ch[v][1]±íÊ¾vµÄÓÒ¶ù×Ó prt[v]±íÊ¾vµÄ¸¸Ç× 
    //val[v]±íÊ¾vµÄÖµ size[v]±íÊ¾ÒÔvÎª¸ù½ÚµãµÄ×ÓÊ÷µÄ½Úµã×ÜÊý cnt[v]±íÊ¾ÖµÎªval[v]µÄµãµÄ¸öÊý
    //rev[v]==1Ê±´ú±íÒªÇø¼ä·­×ª rev[v]==0Ê±±íÊ¾²»ÐèÒªÇø¼ä·­×ª 
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
        //±¾À´Ó¦¸ÃÊÇ·µ»Ø size[ch[root][0]]+1µ«ÎªÁË±ÜÃâÒç³ö£¬ÎÒÏÈinsertÁËinfºÍ-inf£¬ËùÒÔÅÅÃû¾ÍÓ¦¸Ã-1 
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
        if(val[root]<x)return root;//ÌØÅÐÒ»ÏÂ£¬·ÀÖ¹³öÏÖ²éÕÒ²»´æÔÚµÄÊýµÄÇé¿ö 
        ll cur=ch[root][0];
        while(ch[cur][1])cur=ch[cur][1];
        return cur;
    }
    ll succ(ll x){
        find(x);
        if(val[root]>x)return root;//ÌØÅÐÒ»ÏÂ£¬·ÀÖ¹³öÏÖ²éÕÒ²»´æÔÚµÄÊýµÄÇé¿ö
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
        }else ch[nxt][0]=0;splay(nxt);
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
ll n,m,a[maxn];
int main(){
	insert(inf);insert(-inf);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]),insert(a[i]);
	scanf("%lld",&m);
	while(m--){
		char c=getchar();while(c!='A'&&c!='C'&&c!='Q')c=getchar();
		if(c=='A'){
			ll i,p;scanf("%lld%lld",&i,&p);
			remove(a[i]);a[i]-=p;
			if(a[i]>0)insert(a[i]);
			else n--;
		}
		if(c=='C'){
			ll i,p;scanf("%lld%lld",&i,&p);
			remove(a[i]);a[i]+=p;
			if(a[i]>0)insert(a[i]);
			else n--;
		}
		if(c=='Q'){
			ll k;scanf("%lld",&k);
			if(size[root]-2<k)printf("-1\n");
			else printf("%lld\n",val[kth(n-k+2)]);
		}
	}
	printf("%lld",n);
    return 0;
}
/*
5
5 5 5 5 5
5
A 4 2
Q 5
C 3 3
A 3 7
Q 4
*/