#include<cstdio>
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","r",stdout);
	char x;
	int s=0;
	while(x=getchar()){
		if(x=='\n'||x==EOF){
			break;
		}
		if(x>='A'&&x<='Z'){
			continue;
		}
		if(x>='a'&&x<='z'){
			continue;
		}
		s++;
	}
	printf("%d",s);
	return 0;
}
