//cataland
#include <cstdio>
int main() {
	long long n,f=1;
	scanf("%lld",&n);
	for(long long i=1; i<=n; i++) {
		f=f*(4*i-2)/(i+1);
	}
	printf("%lld",f);
	return 0;
}