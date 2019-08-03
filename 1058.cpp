#include<cstdio>

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	int him=0,mom=0;
	int tx;
	for(i=1;i<=12;i++){
		scanf("%d",&tx);
		int t=300-tx;
		if(t>=0){
			him+=t;
			if(him>=100){
				mom+=(him/100)*100;
				him%=100;
			}
//			printf("true:%d\n",i);
		}else{
			if(t+him>=0){
				him+=t;
			}else{
				printf("-%d",i);
				return 0;
			}
//			printf("false:%d\n",i);
		}
	}
	printf("%d",him+(int)((double)mom*1.2));
	return 0;
}
