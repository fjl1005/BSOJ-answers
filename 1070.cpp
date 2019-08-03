
#include<cstdio>
int a[25],s,t;
int n,k;
bool ss(int n) {
	int i;
	if(n==1||n==0)
		return 0;
	if(n==2)
		return 1;
	for(i=2;i*i<=n; i++) {
		if(n%i==0) {
			return 0;
		}
	}
	return 1;
}
void dfs(int step,int m,int num) {
	if(m==k){
		if(ss(num)){
			s++;
		}
		return;
	}
	int i;
	for(i=step;i<=n;i++){
		dfs(i+1,m+1,num+a[i]);
	}
}
int main() {
	int i;
	scanf("%d%d",&n,&k);
	for(i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	dfs(1,0,0);
	printf("%d",s);
	return 0;
}