#include<cstdio>
int a[200005],f[200005];
int max(int a,int b){
	return a>b?a:b;
}
int main() {
	int n,i,Max=-999999;
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		scanf("%d",&a[i]);
		if(i>0){
			f[i]=max(a[i],a[i]+f[i-1]);
		}
		else{
			f[i]=a[i];
		}
	}
	for(i=0;i<n;i++){
		if(f[i]>Max){
			Max=f[i];
		}
	}
	printf("%d",Max);
	return 0;
}