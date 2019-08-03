#include<cstdio>
int a[1010];
int main() {
	int n,i,j,s=0;
	scanf("%d",&n);
	a[1]=3;
	a[2]=7;
	a[3]=17;
	for(i=4; i<=n; i++) {
		a[i]=(a[i-1]*2+a[i-2])%12345;
	}
	printf("%d",a[n]);
	return 0;
}