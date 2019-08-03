#include<cstdio>
int a[400];
bool cheak(int n){
	if(n==0||n==1){
		return 0;
	}
	if(n==2){
		return 1;
	}
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	char x;
	int i;
	while(x=getchar()){
		if(x==EOF||x=='\n'){
			break;
		}
		a[x]++;
	}
	int maxx=-1,minn=105;
	for(i='a';i<='z';i++){
		if(a[i]>maxx){
			maxx=a[i];
		}
		if(a[i]<minn&&a[i]!=0){
			minn=a[i];
		}
	}
	int temp=maxx-minn;
	if(cheak(temp)){
		printf("Lucky Word\n%d",temp);
	}else{
		printf("No Answer\n0");
	}
	return 0;
}
