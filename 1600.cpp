#include<cstdio>
#include<cstring>
char a[2005],b[2005];
int g[2005][2005];
int k;
int max(int a,int b){
	return a>b?a:b;
}
int abs(int x){
	return x>0?x:-x;
}
int main() {
	int a1,b1,up,low,i,j,temp;
	gets(a);
	gets(b);
	scanf("%d",&k);
	a1=strlen(a),b1=strlen(b);
	up=a1+b1;
	low=max(a1,b1);
	g[0][0]=0;
	for(i=1; i<=a1; i++) {
		g[i][0]=k+g[i-1][0];
	}
	for(i=1; i<=b1; i++) {
		g[0][i]=k+g[0][i-1];
	}
	for(i=1; i<=a1; i++) {
		for(j=1; j<=b1; j++) {
			g[i][j]=k+g[i-1][j];
			temp=g[i][j-1]+k;
			if(g[i][j]>temp) {
				g[i][j]=temp;
			}
			temp=g[i-1][j-1]+abs(a[i-1]-b[j-1]);
			if(g[i][j]>temp) {
				g[i][j]=temp;
			}

		}
	}
	printf("%d",g[a1][b1]);
	return 0;
}