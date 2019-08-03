#include<cstdio>
#define LL long long

LL sum[400005];
LL lazy[400005];
LL a[100005];

void pushdown(int v,int l,int r) {
	if(lazy[v]) {
		int mid=l+r>>1;
		lazy[v<<1]+=lazy[v];
		sum[v<<1]+=lazy[v]*(mid-l+1);
		lazy[v<<1|1]+=lazy[v];
		sum[v<<1|1]+=lazy[v]*(r-mid);
		lazy[v]=0;
	}
}

void pushup(int v) {
	sum[v]=sum[v<<1]+sum[v<<1|1];
}

void build(int v,int l,int r) {
	lazy[v]=0;
	if(l==r) {
		sum[v]=a[l];
		return;
	}
	int mid=l+r>>1;
	build(v<<1,l,mid);
	build(v<<1|1,mid+1,r);
	pushup(v);
}

LL query(int v,int l,int r,int left,int right) {
	if(left<=l&&right>=r) {
		return sum[v];
	}
	pushdown(v,l,r);
	LL ans=0;
	int mid=l+r>>1;
	if(left<=mid) {
		ans+=query(v<<1,l,mid,left,right);
	}
	if(right>mid) {
		ans+=query(v<<1|1,mid+1,r,left,right);
	}
	return ans;
}

void update(int v,int l,int r,int left,int right,int add) {
	if(left<=l&&right>=r) {
		sum[v]+=add*(r-l+1);
		lazy[v]+=add;
		return;
	}
	pushdown(v,l,r);
	int mid=l+r>>1;
	if(left<=mid) {
		update(v<<1,l,mid,left,right,add);
	}
	if(right>mid) {
		update(v<<1|1,mid+1,r,left,right,add);
	}
	pushup(v);
}
char s[1005];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	for(int i=1; i<=m; i++) {
		int k;
		int x,y;
		scanf("%s%d%d",s,&x,&y);
		if(s[1]=='d') {
			update(1,1,n,x,x,y);
		} else {
			if(s[1]=='u') {
				update(1,1,n,x,x,-y);
			} else {
				if(s[1]=='s') {
					printf("%lld\n",query(1,1,n,x,y));
				}
			}
		}
	}
	return 0;
}