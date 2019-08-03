#include<cstdio>
#include<cstring>
using namespace std;
char s[100];
int main() {
	int i,j,k,l,n,t;
	char a,b,c;
	bool f;
	gets(s);
	l=strlen(s);
	for(i=l-1; i>=0; i--)
		if(s[i]=='.') {
			l=i+1;
			break;
		}
	scanf("%d",&n);
	for(t=0; t<n; t++) {
		getchar();
		a=getchar();
		if(a=='D') {
			getchar();
			b=getchar();
			f=0;
			for(i=0; i<l; i++) {
				if(s[i]!=b || f)printf("%c",s[i]);
				else f=1;
			}
		}
		if(a=='I') {
			getchar();
			b=getchar();
			getchar();
			c=getchar();
			j=100;
			for(i=l-1; i>=0; i--)
				if(s[i]==b) {
					j=i;
					break;
				}
			for(i=0; i<l; i++) {
				if(i==j)
					printf("%c",c);
				printf("%c",s[i]);
			}
		}
		if(a=='R') {
			getchar();
			b=getchar();
			getchar();
			c=getchar();
			for(i=0; i<l; i++)
				if(s[i]==b)
					printf("%c",c);
				else
					printf("%c",s[i]);
		}
	}
	printf("\n");
	return 0;
}