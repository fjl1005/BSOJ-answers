#include<cstdio>
int a[1005];
int main() {
	int n,i,j,last;
	bool flag;
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++){
		flag=1;
		for(j=i+1;j<n;j++){
			if(a[j]<a[i]){
				if(flag){
					last=a[j];
					flag=0;
					continue;
				}
				if(a[j]>=last){
					printf("NO");
					return 0;
				}
			}
		}
	}
	printf("YES");
	return 0;
}