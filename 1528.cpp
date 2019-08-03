#include<cstdio>
char s;
int main() {
	int temp[2],i,j,n,k;
	int a;
	for(j=0; j<2; j++) {
		s=getchar();
		getchar();
		if(s=='R') temp[j]=0;
		if(s=='S') temp[j]=1;
		if(s=='P') temp[j]=2;
	}
	if(temp[0]==0) {
		if(temp[1]==0)	a=0;
		if(temp[1]==1)	a=1;
		if(temp[1]==2)	a=2;
	}
	if(temp[0]==1) {
		if(temp[1]==1)	a=0;
		if(temp[1]==2)	a=1;
		if(temp[1]==0)	a=2;
	}
	if(temp[0]==2) {
		if(temp[1]==2)	a=0;
		if(temp[1]==0)	a=1;
		if(temp[1]==1)	a=2;
	}
		if(a==0) printf("Equ\n");
		if(a==1) printf("Win\n");
		if(a==2) printf("Fall\n");
	return 0;
}