#include<cstdio>
int a[1010];
int main() {
	int n,i,j;
	scanf("%d",&n);
	a[0]=1;
	a[1]=1;
	for(i=2; i<=n; i++) {
		for(j=0;j<i-1;j++){
			a[i]=(a[i]+a[j]*a[i-j-2])%12345;
		}
		a[i]=(a[i]+a[i-1])%12345;
	}
	printf("%d",a[n]);
	return 0;
}