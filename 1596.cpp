#include<cstdio>
int max(int a,int b) {
	return a>b?a:b;
}
int f[35],w[35],c[35];
int main() {
	int i,j,n,v;
	scanf("%d%d",&v,&n);
	for(i=0; i<n; i++) {
		scanf("%d%d",&w[i],&c[i]);
	}
	for(i=1; i<=n; i++) {
		for(j=0; j<=v; j++) {
			if(w[i]<=j) {
				f[j]=max(f[j],f[j-w[i]]+c[i]);
			}
		}
	}
	printf("%d",f[v]);
	return 0;
}