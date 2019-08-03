#include<cstdio>
#include<algorithm>
using std::sort;
struct f {
	int c,d;
} a[500005];
int cmp(f a,f b) {
	return a.c<b.c;
}
int dp[500005];

int middle(int l,int r,int s) {
	if(l==r) {
		return l;
	}
	if(l==r-1) {
		if(s<dp[l]) {
			return l;
		}
		return r;
	}
	int mid=(l+r)/2;
	if(dp[mid]>s) {
		return middle(l,mid,s);
	}
	if(dp[mid]<s) {
		return middle(mid+1,r,s);
	}
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n;
	scanf("%d",&n);
	int i;
	for(i=1; i<=n; i++) {
		scanf("%d%d",&a[i].c,&a[i].d);
	}
	sort(a+1,a+n+1,cmp);
	int top=0;
	for(i=1; i<=n; i++) {
		if(!top||dp[top]<a[i].d) {
			dp[++top]=a[i].d;
		} else {
			int t=middle(1,top,a[i].d);
			dp[t]=a[i].d;
		}
	}
	printf("%d",top);
	return 0;
}