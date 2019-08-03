#include<cstdio>
int a[1005];
int main() {
	int n,i;
	scanf("%d",&n);
	a[1]=1;
	a[2]=3;
	a[3]=5;
	for(i=4;i<=n;i++){
		a[i]=(a[i-2]*2+a[i-1])%12345;
	}
	printf("%d",a[n]);
	return 0;
}