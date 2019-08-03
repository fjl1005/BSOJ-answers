#include<cstdio>
#include<cmath>
int n,q;
inline double l2(double x) {
	return log(x)/log(2.0);
}
inline int Max(int a,int b){
	return a>b?a:b;
}
inline int Min(int a,int b){
	return a<b?a:b;
}
int a[50005];
int f1[50005][15];
int f2[50005][15];
void begin(){
	for(int i=1;i<=n;i++){
		f1[i][0]=f2[i][0]=a[i];
	}
	for(int j=1;j<=l2(n);j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			f1[i][j]=Max(f1[i][j-1],f1[i+(1<<(j-1))][j-1]);
			f2[i][j]=Min(f2[i][j-1],f2[i+(1<<(j-1))][j-1]);
		}
	}
}
inline int RMQ(int l,int r){
	int k=l2(r-l+1);
	return Max(f1[l][k],f1[r-(1<<k)+1][k])-Min(f2[l][k],f2[r-(1<<k)+1][k]);
}
int main() {
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	begin();
	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",RMQ(l,r));
	}

	return 0;
}