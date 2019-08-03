#include<cstdio>
#define ll long long
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define fa(x) (x>>1)
#define re register

const ll maxn = 400005;
struct SegTree{
	ll sum[maxn]={0},tag[maxn]={0};
	void pushup(ll v){sum[v]=sum[lc(v)]+sum[rc(v)];}
	void pushdown(ll v,ll l,ll r){
		if(tag[v]){
			ll mid=(l+r)>>1;
			tag[lc(v)]+=tag[v];
			tag[rc(v)]+=tag[v];
			sum[lc(v)]+=tag[v]*(mid-l+1);
			sum[rc(v)]+=tag[v]*(r-mid);
			tag[v]=0;
		}
	}
	void update(ll v,ll l,ll r,ll ql,ll qr,ll add){
		if(l>r)return;
		if(ql<=l&&r<=qr){sum[v]+=add*(r-l+1);tag[v]+=add;return;}
		pushdown(v,l,r);
		ll mid=(l+r)>>1;
		if(ql<=mid)update(lc(v),l,mid,ql,qr,add);
		if(qr>mid)update(rc(v),mid+1,r,ql,qr,add);
		pushup(v);
	}
	ll query(ll v,ll l,ll r,ll ql,ll qr){
		if(l>r)return 0;
		if(ql<=l&&r<=qr)return sum[v];
		pushdown(v,l,r);
		ll mid=(l+r)>>1,sum=0;
		if(ql<=mid)sum+=query(lc(v),l,mid,ql,qr);
		if(qr>mid)sum+=query(rc(v),mid+1,r,ql,qr);
		return sum;
	}
};

SegTree T;

ll n=0,m=0;

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=m;i++){
		char ch='A';while(ch=getchar())if(ch=='d'||ch=='u'||ch=='s')break;
		while(getchar()!=' '); 
		ll k,p;scanf("%lld%lld",&k,&p);
		if(ch=='d')T.update(1,1,n,k,k,p);
		if(ch=='u')T.update(1,1,n,k,k,-p);
		if(ch=='s')printf("%lld\n",T.query(1,1,n,k,p));
	}
	return 0;
}
/*
10 6
Add 2 3
Sub 3 1
Ask 3 7
Add 4 2
Ask 3 6
Sub 1 1
*/
