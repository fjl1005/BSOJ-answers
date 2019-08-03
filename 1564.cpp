#include<cstdio>
int main(){
	int n,i,j,s=0,s1=0,s2=0;
	char x,a;
	scanf("%d %c\n",&n,&a);
	bool t;
	for(i=0;i<n;i++){
		t=1;
		for(j=0;;j++){
			x=getchar();
			if(x=='\n'){
				break;
			}
			s1++;
			if(j==0){
				if(x!='c'){
					t=0;
				}
			}
			if(j==1){
				if(x!='o'){
					t=0;
				}
			}
			if(j==2){
				if(x!='n'){
					t=0;
				}
			}
			if(x==a){
				s++;
			}
		}
		if(t==1){
			s2++;
		}
	}
	printf("%d\n%.2lf%%",s2,(double)s/s1*100);
	return 0;
}