#include<cstdio>
int f[50001];
int main() {
	int v,n,i,j,t;
	scanf("%d%d",&n,&v);
	for(i=1; i<=n; i++) {
		int k,w,c;
		scanf("%d%d%d",&k,&w,&c);
		for(t=1; t<=k; t++) {
			bool flag=1;
			for(j=v; j>=w; j--)
				if(f[j]<f[j-w]+c) {
					f[j]=f[j-w]+c;
					flag=0;
				}
			if(flag) {
				break;
			}
		}
	}
	printf("%lld",f[v]);
	return 0;
}