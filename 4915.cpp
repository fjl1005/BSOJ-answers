#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	//freopen("pencil.in","r",stdin);
	//freopen("pencil.out","w",stdout);
	int n,i,a,b,c,Min=0xfffffff;
	scanf("%d",&n);
	for(i=1; i<=3; i++) {
		scanf("%d%d",&a,&b);
		if(n%a==0) {
			c=n/a*b;
		} else {
			c=(n/a+1)*b;
		}
		if(c<Min) {
			Min=c;
		}
	}
	printf("%d",Min);
	return 0;
}
