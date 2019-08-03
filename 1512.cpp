#include<cstdio>
int v[105],p[105];
int l[105],r[105];
int cs[105];
int to[105];
int f[105][32005];
int max(int a,int b) {
	return a>b?a:b;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int i;
	int top=0;
	for(i=1; i<=m; i++) {
		int q;
		scanf("%d%d%d",&v[i],&p[i],&q);
		p[i]*=v[i];
		if(q>0) {
			if(cs[q]==0) {
				l[q]=i;
			} else {
				r[q]=i;
			}
			cs[q]++;
		} else {
			to[++top]=i;
		}
	}
	int j;
	for(i=1; i<=top; i++) {
		for(j=1; j<=n; j++) {
			int k=to[i];
			f[i][j]=f[i-1][j];
			if(j>=v[k]) {
				f[i][j]=max(f[i][j],f[i-1][j-v[k]]+p[k]);
			}
			if(j>=v[k]+v[l[k]]&&cs[k]>=1) {
				f[i][j]=max(f[i][j],f[i-1][j-v[k]-v[l[k]]]+p[k]+p[l[k]]);
			}
			if(j>=v[k]+v[r[k]]&&cs[k]==2) {
				f[i][j]=max(f[i][j],f[i-1][j-v[k]-v[r[k]]]+p[k]+p[r[k]]);
			}
			if(j>=v[k]+v[l[k]]+v[r[k]]&&cs[k]==2) {
				f[i][j]=max(f[i][j],f[i-1][j-v[k]-v[l[k]]-v[r[k]]]+p[k]+p[l[k]]+p[r[k]]);
			}
		}
	}
	printf("%d",f[top][n]);
	return 0;
}