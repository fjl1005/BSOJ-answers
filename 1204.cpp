#include<cstdio>
#define ll long long
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)

inline ll min(ll a,ll b){
	return a<b?a:b;
}

const ll maxn=200010;
const ll inc=100001;

ll sum[maxn<<2],lazy[maxn<<2];

void pushup(ll v){
	sum[v]=sum[lc(v)]+sum[rc(v)];
}

void pushdown(ll v,ll l,ll r){
	if(lazy[v]){
		ll mid=l+r>>1;
		lazy[lc(v)]=lazy[rc(v)]=1;
		sum[lc(v)]=mid-l+1;
		sum[rc(v)]=r-mid;
		lazy[v]=0;
	}
}

void update(ll v,ll l,ll r,ll left,ll right){
	if(left<=l&&r<=right){
		sum[v]=r-l+1,lazy[v]=1;
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

ll le,ri,n;
int main() {
	scanf("%lld%lld%lld",&le,&ri,&n);
	le+=inc,ri+=inc;ri--;
	for(ll i=1;i<=n;i++){
		ll l,r;scanf("%lld%lld",&l,&r);l+=inc,r+=inc;r--;
		update(1,le,ri,l,r);
	}
	printf("%lld",query(1,le,ri,le,ri));
	return 0;
}