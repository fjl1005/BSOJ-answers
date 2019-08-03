#include<cstdio>
long long s=0,c=1,i,j;
int main(){
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		c=1;
		for(j=1;j<=i;j++){
			c*=j;
		}
		s+=c;
	}
	printf("%lld",s);
	return 0;
}