#include<cstdio>
#include<cstring>
char a[20];
int main() {
	int x,y,i;
	bool flag=0;
	gets(a);
	x=0;
	y=strlen(a)-1;
	if(a[0]=='-'){
		flag=1;
		x++;
	}
	while(a[y]=='0'){
		y--;
	}
	while(a[x]=='0'){
		x++;
	}
	if(flag){
		printf("-");
	}
	for(i=y;i>=x;i--){
		printf("%c",a[i]);
	}
	return 0;
}