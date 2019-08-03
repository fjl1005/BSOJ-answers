#include<cstdio>
long long f[55];
int main() {
	long long n,m,i;
	scanf("%lld%lld",&n,&m);
	f[0]=f[1]=1;
	for(i=1; i<=n; i++) {
		if(i==m) {
			f[i]=f[i-1]*2-1;
		}
		else if(i<m) {
			f[i]=f[i-1]*2;
		} else {
			f[i]=f[i-1]*2-f[i-m-1];
		}
	}
	printf("%lld",f[n]);
	return 0;
}