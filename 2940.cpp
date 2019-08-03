#include<cstdio>
#define ll long long
ll a[100005];
int n,k,l,r;
ll f[100005];
#define min(a,b) a<b?a:b;
struct f {
	int p;
	ll v;
} q[100005];
int main() {
	int i;
	ll sum=0;
	scanf("%d%d",&n,&k);
	for(i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	for (i=1; i<=n; i++) {
		f[i]=q[l].v+a[i];
		while (l<=r&&q[r].v>=f[i]) r--;
		q[++r].p=i;
		q[r].v=f[i];
		while (l<=r&&q[l].p<i-k) l++;
	}
	long long mn=0xffffffffffff;
	for(i=n-k;i<=n;i++){
		mn=min(mn,f[i]);
	}
	printf("%lld",sum-mn);
	return 0;
}