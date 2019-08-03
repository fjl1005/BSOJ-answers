#include<cstdio>
//×î³¤²»½µ×ÓÐòÁÐ 
int max(int x,int y){
	return x>y?x:y;
}
int n,ans,tot,sum;
int a[5005],f[5005],g[5005];
int main() {
//	freopen("t1.in","r",stdin);
//	freopen("t1.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	if(n==1){
		printf("1 1");
		return 0;
	}
	for(i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	for(i=0; i<n; i++) {
		f[i]=1;
		for(j=0; j<i; j++) {
			if(a[i]<a[j]) {
				f[i]=max(f[i],f[j]+1);
			}
			ans=max(ans,f[i]);
		}
	}
	printf("%d ",ans);
	for(i=0; i<n; i++) {
		for(j=0; j<i; j++)
			if(a[i]<a[j]&&f[j]+1==f[i]) {
				g[i]+=g[j];
			}
		for(j=0; j<i; j++) {
			if(f[i]==f[j]&&a[i]==a[j]) {
				g[j]=0;
			}
		}
		if(f[i]==1) {
			g[i]=1;
		}
	}
	for(i=0; i<n; i++) {
		if(f[i]==ans) {
			sum+=g[i];
		}
	}
	printf("%d",sum);
	return 0;
}