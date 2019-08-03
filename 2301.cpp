#include<cstdio>
int a[15]= {6,2,5,5,4,5,6,3,7,6};
int main() {
	int i,j,k,n,s=0,sum=0,i1,j1,k1;
	scanf("%d",&n);
	n-=4;
	for(i=0; i<1111; i++) {
		for(j=0; j<1111; j++) {
			sum=0;
			k=i+j;
			i1=i;
			j1=j;
			k1=k;
			do {
				sum+=a[i1%10];
				i1/=10;
			} while(i1);
			do {
				sum+=a[j1%10];
				j1/=10;
			} while(j1);
			do {
				sum+=a[k1%10];
				k1/=10;
			} while(k1);
			if(sum==n) {
				s++;
			}
		}
	}
	printf("%d",s);
	return 0;
}