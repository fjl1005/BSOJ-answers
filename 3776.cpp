#include<cstdio>
int a[100005];
int main(){
	int i,n,tot=0,t,s=1;
	scanf("%d",&n);
	scanf("%d",&t);
	a[0]=t;
	for(i=1;i<n;i++){
		scanf("%d",&t);
		if(t>a[tot]){
			s++;
			tot++;
			a[tot]=t;
		}
		while(1){
			if(tot==-1){
				s++;
				tot++;
				a[tot]=t;
				break;
			}
			if(t==a[tot]){
				break;
			}
			if(t>a[tot]){
				s++;
				tot++;
				a[tot]=t;
				break;
			}
			tot--;
		}
	}
	printf("%d",s);
	return 0;
} 