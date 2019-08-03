#include<cstdio>
int v[205],f[10005];
int min(int a,int b) {
	return a<b?a:b;
}
int main() {
	int i,j,k,n,m;
	scanf("%d%d",&n,&m);
	for(i=1; i<=n; i++) {
		scanf("%d",&v[i]);
	}
	for(i=1; i<=m; i++) {
		for(j=1; j<=n; j++) {
			if(v[j]<=i) {
				if(f[i]>0) {
					f[i]=min(f[i],f[i-v[j]]+1);
				} else {
					f[i]=f[i-v[j]]+1;
				}
			}
		}
		if(f[i]) {
			printf("%d\n",f[i]);
		} else {
			printf("-1\n");
		}
	}
	return 0;
}