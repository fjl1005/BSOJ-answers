#include<cstdio>
#define ll long long
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)

inline ll min(ll a,ll b){
	return a<b?a:b;
}

const ll maxn=100010;
const ll inf=1<<30;

ll minn[maxn<<2],lazy[maxn<<2];

void pushup(ll v){
	minn[v]=min(minn[lc(v)],minn[rc(v)]);
}

void pushdown(ll v,ll l,ll r){
	if(lazy[v]){
		lazy[lc(v)]+=lazy[v];
		lazy[rc(v)]+=lazy[v];
		minn[lc(v)]+=lazy[v];
		minn[rc(v)]+=lazy[v];
		lazy[v]=0;
	}
}

void update(ll v,ll l,ll r,ll left,ll right,ll add){
	if(left<=l&&r<=right){
		minn[v]+=add,lazy[v]+=add;
		return;
	}
	pushdown(v,l,r);
	ll mid=l+r>>1;
	if(left<=mid)update(lc(v),l,mid,left,right,add);
	if(right>mid)update(rc(v),mid+1,r,left,right,add);
	pushup(v);
}

ll query(ll v,ll l,ll r,ll left,ll right){
	if(left<=l&&r<=right)return minn[v];
	pushdown(v,l,r);
	ll mid=l+r>>1,a=inf,b=inf;
	if(left<=mid)a=query(lc(v),l,mid,left,right);
	if(right>mid)b=query(rc(v),mid+1,r,left,right);
	return min(a,b);
}

ll c,s,r;
int main() {
	scanf("%lld%lld%lld",&c,&s,&r);c--;
	update(1,1,c,1,c,s);
	for(ll i=1;i<=r;i++){
		ll l,r,n;scanf("%lld%lld%lld",&l,&r,&n);r--;
		ll ans=query(1,1,c,l,r);
		if(ans>=n)printf("YES\n"),update(1,1,c,l,r,-n);
		else printf("NO\n");
	}
	return 0;
}