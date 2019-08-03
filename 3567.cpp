#include<cstdio>
int a[35],n;
char c[35];
bool cheak(){
	int i,s=0;
	for(i=0;i<n;i++){
		if(s<0||s>5){
			return 0;
		}
		if(c[i]=='B'){
			s++;
		}
		if(c[i]=='C'){
			s--;
		}
	}
	return 1;
}
int main(){
	int i,j,t=1,top=0;
	scanf("%d\n",&n);
	gets(c);
	if(!cheak()){
		printf("No");
		return 0;
	}
	printf("Yes\n");
	for(i=0;i<n;i++){
		if(c[i]=='A'){
			printf("%d\n",t);
			t++;
		}
		if(c[i]=='B'){
			a[top++]=t;
			t++;
		}
		if(c[i]=='C'){
			printf("%d\n",a[--top]);
		}
	}
	return 0;
}