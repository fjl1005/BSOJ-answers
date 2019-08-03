#include<cstdio>
int f[205];
int Min(int a,int b) {
	return a<b?a:b;
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=14;i++){
		f[i]=i;
	}
	for(i=14; i<=n; i++) {
		int minn=0xfffffff;
		int t;
		for(j=1; j<i; j++) {
			if(i%j==0){
				t=i/j-1;
			}else{
				t=i/j;
			}
			int temp=f[j]+t*2+5;
			if(temp<minn){
				minn=temp;
			}
		}
		f[i]=Min(f[i-1]+1,minn);
	}
//	int Minn=0xfffffff;
//	for(i=n;i<=200;i++){
//		if(f[i]<Minn){
//			Minn=f[i];
//		}
//	}
	printf("%d",f[n]);
	return 0;
}
