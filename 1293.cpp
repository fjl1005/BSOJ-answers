#include<cstdio>
int main() {
	int n,i,j,a,b,x,y;
	scanf("%d %d %d",&n,&i,&j);
	for(a=1; a<=n; a++) {
		printf("(%d,%d)",i,a);
	}
	printf("\n");
	for(b=1; b<=n; b++) {
		printf("(%d,%d)",b,j);
	}
	printf("\n");
	x=i;
	y=j;
	for(; x>1&&y>1; y--) {
		x--;
	}
	a=x;
	for(b=y; b<=n&&a<=n; b++) {
		printf("(%d,%d)",a,b);
		a++;
	}
	printf("\n");
	x=i;
	y=j;
	for(; x<n&&y>1; y--) {
		x++;
	}
	a=x;
	for(b=y; b<=n&&a>=1; b++) {
		printf("(%d,%d)",a,b);
		a--;
	}
	return 0;
}