#include<cstdio>
int a[25],n,Min=0xfffffff;
int Abs(int x){
	return x>0?x:-x;
}

void dfs(int A,int B,int i){
	if(i==n+1){
		int t=Abs(A-B);
		if(t<Min){
			Min=t;
		}
		return;
	}
	dfs(A+a[i],B,i+1);
	dfs(A,B+a[i],i+1);
	return;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(0,0,1);
	printf("%d",Min);
	return 0;
}
