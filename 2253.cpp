#include<cstdio>
long long f[100];
long long dfs(long long n){
	if(n==0){
		return 0;
	}
	for(int i=91;i>=0;i--){
		if(f[i]<=n){
			return f[i-1]+dfs(n-f[i]);
		}
	}
}
int main(){
	long long a,b;
	int Q,i;
	f[0]=f[1]=1;
	for(i=2;i<92;i++){
		f[i]=f[i-1]+f[i-2];
	}
	scanf("%d",&Q);
	for(int i=0;i<Q;i++){
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",dfs(b)-dfs(a-1));
	}
	return 0;
}