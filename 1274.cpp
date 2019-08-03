#include<cstdio>
#include<algorithm>
void f(int n) {
	int i,a[16],p=0;
	for (i=0; n>0; n>>=1,i++)
		a[i]=n%2==1;
	for (i--; i>1; i--)
		if (a[i]%2==1) {
			if (p)
				printf("+");
			printf("2(");
			f(i);
			printf(")");
			p=1;
		}
	if (a[1]%2==1) {
		if (p)
			printf("+");
		printf("2");
		p=1;
	}
	if (a[0]%2==1) {
		if (p)
			printf("+"); 
		printf("2(0)");
	}
	return;
}
int main() {
	int n;
	scanf("%d",&n);
	f(n);
	return 0;
}