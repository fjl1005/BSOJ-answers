#include<cstdio>
#include<cstring>
int main() {
	int n,i,j,s,t;
	char a[10];
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		s=0;
		sprintf(a,"%d",i);
		t=strlen(a);
		for(j=0;j<t;j++){
			s+=(a[j]-'0')*(a[j]-'0')*(a[j]-'0');
		}
		if(i==s){
			printf("%d\n",i);
		}
	}
	return 0;
}