#include<cstdio>
#define inf 999999999
int f1[300][300],f2[300][300],num[300];
int s[300];
int max(int a,int b) {
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
int d(int i,int j) {
	return s[j]-s[i-1];
}
int main() {
	int n,minl,maxl;
	scanf("%d",&n);
	int i,j,p,k;
	for(i=1; i<=n; i++) {
		scanf("%d",&num[i]);
		num[i+n]=num[i];
	}
	for(i=1;i<=n+n;i++){
		s[i]=s[i-1]+num[i];
	}
	for(p=1; p<n; p++)  {
		for(i=1,j=i+p; (j<n+n) && (i<n+n); i++,j=i+p) {
			f2[i][j]=inf;
			for(k=i; k<j; k++) {
				f1[i][j] = max(f1[i][j], f1[i][k]+f1[k+1][j]+d(i,j));
				f2[i][j] = min(f2[i][j], f2[i][k]+f2[k+1][j]+d(i,j));
			}
		}
	}
	minl=inf;
	maxl=-1;
	for(int i=1; i<=n; i++) {
		maxl=max(maxl,f1[i][i+n-1]);
		minl=min(minl,f2[i][i+n-1]);
	}
	printf("%d\n%d",minl,maxl);
	return 0;
}