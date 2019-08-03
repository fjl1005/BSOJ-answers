#include<cstdio>
int main(){
	int l,r,i,j,s=0;
	scanf("%d%d",&l,&r);
	for(i=l;i<=r;i++){
		j=i;
		while(j){
			if(j%10==2){
				s++;
			}
			j/=10;
		}
	}
	printf("%d",s);
	return 0;
}