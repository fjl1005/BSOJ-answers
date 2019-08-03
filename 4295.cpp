#include<cstdio>

#define ll long long
ll a[200005];
namespace splay{
    ll max(ll a,ll b){return a>b?a:b;}
    const ll inf=1<<30;
    const ll maxn=200010;
    ll root=0,decnt=0;
    ll ch[maxn][2],prt[maxn],size[maxn];
    ll val[maxn],maxx[maxn],rev[maxn],add[maxn],sum[maxn];
    ll chk(ll v){return ch[prt[v]][1]==v;}
    void swap(ll &a,ll &b){a^=b^=a^=b;}
    void pushup(ll v){
		size[v]=size[ch[v][0]]+size[ch[v][1]]+1;
		maxx[v]=max(val[v],max(maxx[ch[v][0]],maxx[ch[v][1]]));
		sum[v]=sum[ch[v][0]]+sum[ch[v][1]]+val[v];
	}
    void pushdown(ll v){
        if(rev[v]){
            if(ch[v][0])rev[ch[v][0]]^=1,swap(ch[ch[v][0]][0],ch[ch[v][0]][1]);
            if(ch[v][1])rev[ch[v][1]]^=1,swap(ch[ch[v][1]][0],ch[ch[v][1]][1]);
            rev[v]=0;
        }
        if(add[v]){
        	if(ch[v][0])val[ch[v][0]]+=add[v],add[ch[v][0]]+=add[v],maxx[ch[v][0]]+=add[v],sum[ch[v][0]]+=add[v]*size[ch[v][0]];
			if(ch[v][1])val[ch[v][1]]+=add[v],add[ch[v][1]]+=add[v],maxx[ch[v][1]]+=add[v],sum[ch[v][1]]+=add[v]*size[ch[v][1]];
        	add[v]=0;
        } 
    }
    void link(ll son,ll fa,ll k){
    	prt[son]=fa;
    	ch[fa][k]=son;
    }
    void rotate(ll x){
        ll y=prt[x],z=prt[y],d=chk(x),k=chk(y);
        ll u=ch[x][d^1];
		link(u,y,d);
		link(y,x,d^1);
		link(x,z,k);
        pushup(y),pushup(x);
    }
    void splay(ll cur,ll goal=0){
        while(prt[cur]!=goal){
            ll y=prt[cur],z=prt[y];
            if(z!=goal){
                if(chk(cur)==chk(y))rotate(y);
                else rotate(cur);
            }
            rotate(cur);
        }
        if(!goal)root=cur;
    }
    ll kth(ll k){
        ll cur=root;
        while(true){
            pushdown(cur);
            if(size[ch[cur][0]]>=k)cur=ch[cur][0];
            else if(size[ch[cur][0]]+1<k)k-=size[ch[cur][0]]+1,cur=ch[cur][1];
            else return cur;
        }
    }
    ll split(ll l,ll r){
    	l=kth(l),r=kth(r+2);
    	splay(l),splay(r,l);
    	return ch[ch[root][1]][0];
    }
    void update(ll l,ll r,ll ad){
    	ll cur=split(l,r);
    	add[cur]+=ad,val[cur]+=ad,maxx[cur]+=ad,sum[cur]+=ad*size[cur];
        pushup(ch[root][1]),pushup(root);
    }
    void reverse(ll l,ll r){
    	ll cur=split(l,r);
        rev[cur]^=1;
        swap(ch[cur][0],ch[cur][1]);
        pushup(ch[root][1]),pushup(root);
    }
    ll querymax(ll l,ll r){
    	return maxx[split(l,r)];
    }
    ll querysum(ll l,ll r){
    	return sum[split(l,r)];
    }
    ll build(ll l,ll r,ll fa){
    	if(l>r)return 0;
    	if(l==r){
    		prt[l]=fa;
    		val[l]=maxx[l]=sum[l]=a[l];
    		size[l]=1;
    		return l;
    	}
    	ll mid=l+r>>1;
    	ch[mid][0]=build(l,mid-1,mid);
    	ch[mid][1]=build(mid+1,r,mid);
    	val[mid]=a[mid];
    	prt[mid]=fa;
    	pushup(mid);
    	return mid;
    }
}
using namespace splay;
ll n,m;
int main(){
    scanf("%lld%lld",&n,&m);
    a[1]=a[n+2]=maxx[0]=-inf;
    for(ll i=2;i<=n+1;i++)scanf("%lld",&a[i]);
    root=build(1,n+2,0);
    while(m--){
    	ll k,l,r;scanf("%lld%lld",&k,&l);
    	if(k==1)printf("%lld\n",querysum(l,l));
    	else{
    		scanf("%lld",&r);
    		if(k==2)update(l,l,r);
    		if(k==3)printf("%lld\n",querysum(l,r));
    		if(k==4)printf("%lld\n",querymax(l,r));
    		if(k==5)reverse(l,r);
    	}
    }
    return 0;
}
/*
6 8
1 2 3 4 5 6
3 1 6
 */ 