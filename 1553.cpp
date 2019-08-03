#include<cstdio>
#include<cstring>
int a[10005],b[10005],c[10005];
int Max(int a,int b){
	return a>b?a:b;
}
void add(){
	int n=Max(a[0],b[0]),i,t=0;
	for(i=1;i<=n;i++){
		c[i]=a[i]+b[i]+t;
		t=c[i]/10;
		c[i]%=10;
	}
	if(t>0){
		c[0]=n+1;
		c[c[0]]=t;
	}else{
		c[0]=n;
	}
	return;
}
char t[10005];
void init(){
	gets(t);
	a[0]=strlen(t);
	int i;
	for(i=0;i<a[0];i++){
		a[a[0]-i]=t[i]-'0';
	}
	gets(t);
	b[0]=strlen(t);
	for(i=0;i<b[0];i++){
		b[b[0]-i]=t[i]-'0';
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","r",stdout);
	init();
	add();
	for(int i=c[0];i>=1;i--){
		printf("%d",c[i]);
	}
	return 0;
}
