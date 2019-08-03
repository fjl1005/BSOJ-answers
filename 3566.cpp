#include<cstdio>
#include<cstring>
char a[1000005],b[1000005];
int main(){
	int n,i,j,s=0,top;
	scanf("%d\n",&n);
	for(i=0;i<n;i++){
		top=0;
		gets(a);
		int len=strlen(a);
		for(j=len-1;j>=0;j--){
			if(a[j]=='#'){
				break;
			}
			else if(a[j]=='$'){
				s++;
			}
			else{
				if(s>0){
					s--;
					continue;
				}else{
					b[top++]=a[j];
				}
			}
		}
		for(j=top-1;j>=0;j--){
			putchar(b[j]);
		}
		puts("");
	}
	return 0;
}