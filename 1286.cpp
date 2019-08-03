#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char a[105];

char b[105];

int main(){
	gets(a+1);
	int n=strlen(a+1);
	int s=0;
	strcpy(b+1,a+1);
	sort(a+1,a+n+1);
	do{
//		puts(a+1);
//		puts(b+1);
		s++;
		if(strcmp(a+1,b+1)==0){
			printf("%d",s);
			return 0;
		}
	}while(next_permutation(a+1,a+n+1));
	return 0;
}