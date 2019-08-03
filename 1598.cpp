#include<cstdio>
#include<cstring>
char a[3005];
char b[3005];
int t[3005][3005];
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	gets(a+1);
	gets(b+1);
	int n=strlen(a+1),m=strlen(b+1);
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i]==b[j]){
				t[i][j]=t[i-1][j-1]+1;
			}else{
				t[i][j]=max(t[i-1][j],t[i][j-1]);
			}
		}
	}
	printf("%d\n",t[n][m]);
	return 0;
}