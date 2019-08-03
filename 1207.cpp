#include<cstdio>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define fa(x) (x>>1)
#define ll long long

const ll unit=100001;
//1 full 0 empty -1 some

const ll maxn=100005,maxm=800005;

ll sum[maxm],tag[maxm];

void pushup(ll v){sum[v]=sum[lc(v)]+sum[rc(v)];}

void pushdown(ll v,ll l,ll r){
	if(tag[v]){
		ll mid=(l+r)>>1;
		tag[lc(v)]+=tag[v];
		tag[rc(v)]+=tag[v];
		sum[lc(v)]+=tag[v];
		sum[rc(v)]+=tag[v];
		tag[v]=0;
	}
}

void update(ll v,ll l,ll r,ll ul,ll ur){
	if(l>r)return;
	if(ul<=l&&r<=ur){sum[v]++;tag[v]++;return;}
	pushdown(v,l,r);
	ll mid=(l+r)>>1;
	if(ul<=mid)update(lc(v),l,mid,ul,ur);
	if(ur>mid)update(rc(v),mid+1,r,ul,ur);
	pushup(v);
}

ll ans=0;
void query(ll v,ll l,ll r,ll q){
	if(l>r)return;
	if(l==r){ans=sum[v];return;}
	pushdown(v,l,r);
	ll mid=(l+r)>>1;
	if(q<=mid)query(lc(v),l,mid,q);
	else query(rc(v),mid+1,r,q);
}

ll n;

int main(){
	ll a=1,b=200000,xc;scanf("%lld%lld",&xc,&n);
	for(ll i=1;i<=n;i++){ll l,r,c;scanf("%lld%lld%lld",&l,&r,&c);if(l==r){i--,n--;continue;}l+=unit,r+=unit;r--;update(1,a,b,l,r);}
	ll q;scanf("%lld",&q);q+=unit;query(1,a,b,q);
	printf("%lld",ans);
	return 0;
}

/*
1 4
2 6 2
1 5 3
3 4 2
7 8 4
3

*/