#include<cstdio>
int main(){
	int k,i,s1,s2,s3;
	bool flag=1;
	scanf("%d",&k);
	for(i=10000;i<=30000;i++){
		s1=i%1000;
		s2=i/10%1000;
		s3=i/100%1000;
		if(s1%k==0&&s2%k==0&&s3%k==0){
			flag=0;
			printf("%d\n",i);
		}
	}
	if(flag){
		printf("No");
		return 0;
	}
	return 0;
}