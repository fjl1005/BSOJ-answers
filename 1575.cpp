#include<cstdio>
long long f[200];
int main() {
	long long n;
	scanf("%lld",&n);
	f[1]=0;
	f[2]=1;
	for (long long i=3; i<=n; i++)
		f[i]=(i-1)*f[i-1]+f[i-2]*(i-1);
	printf("%lld",f[n]);
	return 0;
}