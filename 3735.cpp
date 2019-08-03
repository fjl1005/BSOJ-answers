#include<cstdio>
#define LL long long
LL a[400005];
LL sum[400005];
LL lazy[400005];

void pushdown(LL v,LL l,LL r) {
	if(lazy[v]) {
		LL mid=l+r>>1;
		lazy[v<<1]+=lazy[v];
		sum[v<<1]+=lazy[v]*(mid-l+1);
		lazy[v<<1|1]+=lazy[v];
		sum[v<<1|1]+=lazy[v]*(r-mid);
		lazy[v]=0;
	}
}

void pushup(LL v) {
	sum[v]=sum[v<<1]+sum[v<<1|1];
}

void build(LL v,LL l,LL r) {
	lazy[v]=0;
	if(l==r) {
		sum[v]=a[l];
		return;
	}
	LL mid=l+r>>1;
	build(v<<1,l,mid);
	build(v<<1|1,mid+1,r);
	pushup(v);
}

LL query(LL v,LL l,LL r,LL left,LL right) {
	if(left<=l&&right>=r) {
		return sum[v];
	}
	pushdown(v,l,r);
	LL ans=0;
	LL mid=l+r>>1;
	if(left<=mid) {
		ans+=query(v<<1,l,mid,left,right);
	}
	if(right>mid) {
		ans+=query(v<<1|1,mid+1,r,left,right);
	}
	return ans;
}

void update(LL v,LL l,LL r,LL left,LL right,LL add) {
	if(left<=l&&right>=r) {
		sum[v]+=add*(r-l+1);
		lazy[v]+=add;
		return;
	}
	pushdown(v,l,r);
	LL mid=l+r>>1;
	if(left<=mid) {
		update(v<<1,l,mid,left,right,add);
	}
	if(right>mid) {
		update(v<<1|1,mid+1,r,left,right,add);
	}
	pushup(v);
}
int main() {
	LL n,m;
	scanf("%lld%lld",&n,&m);
	for(LL i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
	}
	build(1,1,n);
	for(LL i=1; i<=m; i++) {
		char ch;
		while(ch=getchar()) {
			if(ch=='C'||ch=='Q')break;
		}
		if(ch=='C') {
			LL l,r,add;
			scanf("%lld%lld%lld",&l,&r,&add);
			update(1,1,n,l,r,add);
		} else {
			if(ch=='Q') {
				LL l,r;
				scanf("%lld%lld",&l,&r);
				printf("%lld\n",query(1,1,n,l,r));
			}
		}
	}
	return 0;
}