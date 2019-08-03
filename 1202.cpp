#include<cstdio>
#define ll long long
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)

const ll maxn=100010;

ll sum[maxn<<2],lazy[maxn<<2];

void pushup(ll v){
	sum[v]=sum[lc(v)]+sum[rc(v)];
}

void pushdown(ll v,ll l,ll r){
	if(lazy[v]){
		ll mid=l+r>>1;
		lazy[lc(v)]=lazy[v];
		lazy[rc(v)]=lazy[v];
		if(lazy[v]==1){
			sum[lc(v)]=mid-l+1;
			sum[rc(v)]=r-mid;
		}else sum[lc(v)]=sum[rc(v)]=0;
		lazy[v]=0;
	}
}

void update(ll v,ll l,ll r,ll left,ll right,ll set){
	if(left<=l&&r<=right){
		if(set==1)sum[v]=r-l+1;
		else sum[v]=0;
		lazy[v]=set;
		return;
	}
	pushdown(v,l,r);
	ll mid=l+r>>1;
	if(left<=mid)update(lc(v),l,mid,left,right,set);
	if(right>mid)update(rc(v),mid+1,r,left,right,set);
	pushup(v);
}

ll query(ll v,ll l,ll r,ll left,ll right){
	if(left<=l&&r<=right)return sum[v];
	pushdown(v,l,r);
	ll mid=l+r>>1,ans=0;
	if(left<=mid)ans+=query(lc(v),l,mid,left,right);
	if(right>mid)ans+=query(rc(v),mid+1,r,left,right);
	return ans;
}

ll n,m;
int main() {
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=m;i++){
		ll opt,l,r;scanf("%lld%lld%lld",&opt,&l,&r);r--;
		if(opt==1)update(1,1,n,l,r,1);
		else update(1,1,n,l,r,-1);
	}
	printf("%lld",query(1,1,n,1,n-1));
	return 0;
}