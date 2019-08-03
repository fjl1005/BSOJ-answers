#include<cstdio>
#include<cmath>
bool zs(double a){
	if((int)a==a){
		return 1;
	}
	return 0;
}
int main() {
	int m,a,i,j;
	double h;
	scanf("%d",&m);
	for(i=1; i<=m/2+1; i++) {
		h=sqrt(2*m+(i-0.5)*(i-0.5))-0.5;
		if(zs(h)){
			printf("%d %d\n",i,(int)h);
		}
	}
	return 0;
}