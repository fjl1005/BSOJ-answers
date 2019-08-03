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
		lazy[lc(v)]^=1;
		lazy[rc(v)]^=1;
		sum[lc(v)]=mid-l+1-sum[lc(v)];
		sum[rc(v)]=r-mid-sum[rc(v)];
		lazy[v]=0;
	}
}

void update(ll v,ll l,ll r,ll left,ll right){
	if(left<=l&&r<=right){
		lazy[v]^=1;sum[v]=r-l+1-sum[v];
		return;
	}
	pushdown(v,l,r);
	ll mid=l+r>>1;
	if(left<=mid)update(lc(v),l,mid,left,right);
	if(right>mid)update(rc(v),mid+1,r,left,right);
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
//	update(1,1,n,1,n);
	for(ll i=1;i<=m;i++){
		ll opt;scanf("%lld",&opt);
		if(opt==1){
			ll l,r;scanf("%lld%lld",&l,&r);
			update(1,1,n,l,r);
		}
		if(opt==2){
			ll l;scanf("%lld",&l);
			printf("%lld\n",query(1,1,n,l,l));
		}
	}
	return 0;
}