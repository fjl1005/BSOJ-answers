#include<cstdio>
int dp[200005];
int a[200005];

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
		scanf("%d",&a[i]);
	}
	int top=0;
	for(i=1; i<=n; i++) {
		if(!top||dp[top]<a[i]) {
			dp[++top]=a[i];
		} else {
			int t=middle(1,top,a[i]);
			dp[t]=a[i];
		}
	}
	printf("%d",n-top);
	return 0;
}
