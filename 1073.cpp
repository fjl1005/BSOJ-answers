#include<cstdio>
int a[105];
int main(){
	int n,i,s=0,sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		s+=a[i];
	}
	s/=n;
	for(i=0;i<n;i++){
		a[i]-=s;
	}
	for(i=0;i<n-1;i++){
		if(a[i]){
			a[i+1]+=a[i];
			sum++;
		}
	}
	printf("%d",sum);
	return 0;
}