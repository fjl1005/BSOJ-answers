#include<cstdio>
inline int abs(int x) {
	return x>0?x:-x;
}
int main() {
	int n,i,x;
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		scanf("%d",&x);
		if(x==0) {
			continue;
		}
		char ch=x>0?'+':'-';
		if(i>1||(i==1&&x<0)) {
			putchar(ch);
		}
		x=abs(x);
		if(x!=1) {
			printf("%d",x);
		}
		if(i<n) {
			printf("x^%d",n-i+1);
		} else {
			printf("x");
		}
	}
	scanf("%d",&x);
	if(x!=0) {
		if(x>0) {
			printf("+%d",x);
		}else{
			printf("%d",x);
		}
	}
	return 0;
}