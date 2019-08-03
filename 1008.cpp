#include<cstdio>
int main() {
	int x,y,max=0,maxi=0,i;
	for(i=1; i<=7; i++) {
		scanf("%d%d",&x,&y);
		if(x+y>8 && max<x+y) {
			max=x+y;
			maxi=i;
		}
	}
	printf("%d",maxi);
	return 0;
}