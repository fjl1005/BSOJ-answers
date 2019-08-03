#include<cstdio>
#include<cstring>
char name[105];
int money[105];
char answer[105];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n;
	scanf("%d",&n);
	
	int Max=-1;
	int sum=0;
//	getchar();
	int i;
	int sl,sc,lw;
	char yy,nn;
	for(i=1;i<=n;i++){
		int s=0;
//		printf("##############\n");
		scanf("%s %d %d %c %c %d",name,&sl,&sc,&yy,&nn,&lw);
		if(sl>80&&lw>=1){
			s+=8000;
		}
		if(sl>85&&sc>80){
			s+=4000;
		}
		if(sl>90){
			s+=2000;
		}
		if(sl>85&&nn=='Y'){
			s+=1000;
		}
		if(sc>80&&yy=='Y'){
			s+=850;
		}
		sum+=s;
		if(s>Max){
			Max=s;
			strcpy(answer,name);
		}
	}
	puts(answer);
	printf("%d\n%d",Max,sum);
	return 0;
}
