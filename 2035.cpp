#include<cstdio>
int a[1005],b[1005];
int main() {
	int n,i,j,s=1;
	scanf("%d",&n);
	a[1]=9;
	b[1]=1;
	for(i=2;i<=n;i++){
		int x=9;
		if(i==n)
			x--;
		a[i]=(a[i-1]*x+b[i-1])%12345;
		b[i]=(a[i-1]+b[i-1]*x)%12345;
	}
	printf("%d",a[n]);
	return 0;
}