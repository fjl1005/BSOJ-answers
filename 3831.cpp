#include<cstdio>
int a[100001];
int main() {
	int x,ans=0,n,s=0,i;
	char c;
	scanf("%d",&a[0]);
	while(scanf("%c",&c)&&c!='\n') {
		scanf("%d",&x);
		x=x%10000;
		if(c=='+') {
			a[++ans]=x;
			continue;
		}
		n=a[ans];
		a[ans]=(n*x)%10000;
	}
	for(i=0; i<=ans; i++) {
		s+=a[i];
	}
	s%=10000;
	printf("%d",s);
	return 0;
}