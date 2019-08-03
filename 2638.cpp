#include<cstdio>
#include<cstring>
char key[305],dic[305];

char jm[105],yu[105],pl[105];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	gets(jm+1);
	gets(yu+1);
	gets(pl+1);
	int l=strlen(jm+1);
	int lp=strlen(pl+1);
	if(l<26){
		printf("Failed");
		return 0;
	}
	int i;
	for(i=1;i<=l;i++){
		if(key[yu[i]]){
			if(key[yu[i]]!=jm[i]){
				printf("Failed");
				return 0;
			}
		}else{
			key[yu[i]]=jm[i];
		}
		if(dic[jm[i]]){
			if(dic[jm[i]]!=yu[i]){
				printf("Failed");
				return 0;
			}
		}else{
			dic[jm[i]]=yu[i];
		}
	}
	for(i='A';i<='Z';i++){
		if(!key[i]||!dic[i]){
			printf("Failed");
			return 0;
		}
	}
	for(i=1;i<=lp;i++){
		putchar(dic[pl[i]]);
	}
	return 0;
}
