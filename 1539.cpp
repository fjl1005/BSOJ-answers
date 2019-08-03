#include<cstdio>
int main(){
	long long i,a[100];
	a[1]=0;
	a[2]=1;
	scanf("%lld",&a[0]);
	for(i=3;i<=a[0];i++){
		a[i]=a[i-1]+a[i-2];
	}
	printf("%lld",a[a[0]]);
	return 0;
}