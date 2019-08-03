#include<cstdio>
int a[1010],b[1010];
int main() {
	int n,i,j,s=0;
	scanf("%d",&n);
	a[1]=3;
	b[1]=1;
	for(i=2;i<=n;i++){
		a[i]=a[i-1]*3%12345+b[i-1]*2%12345;
		b[i]=(a[i-1]+b[i-1])%12345;
	}
	printf("%d",(a[n]+b[n])%12345);
	return 0;
}