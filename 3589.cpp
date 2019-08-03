#include<cstdio>
#include<cstring>
int next[1000005];
char p[1000005],t[1000005];
void cale(){
	next[0]=-1;
	int j=0;
	int k=-1;
	int pl=strlen(p);
	while(j<pl){
		if(k==-1||p[j]==p[k]){
			next[++j]=++k;
		}else{
			k=next[k];
		}
	}
}
int kmp(){
	int i=0;
	int j=0;
	int tl=strlen(t),pl=strlen(p);
	int s=0;
	while(i<tl){
		if(j==-1||t[i]==p[j]){
			i++;
			j++;
		}else{
			j=next[j];
		}
		if(j==pl){
			s++;
		}
	}
	return s;
}
int main(){
	int n;
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++){
		gets(p);
		gets(t);
		cale();
		printf("%d\n",kmp());
	}
	return 0;
}