#include<cstdio>
int sum[200005],num[200005],q[200005];
int main(){
	int n,m,x,ans=-0xffffff,i;
	int head=1,tail=1;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		sum[i]=x+sum[i-1];
		if(ans<sum[i]-q[head]){
			ans=sum[i]-q[head];
		}
		while(sum[i]<=q[tail]&&tail>0){
			tail--;
		}
		q[++tail]=sum[i];
		num[tail]=i;
		while(num[head]+m<=i){
			head++;
		}
	}
	printf("%d",ans);
	return 0;
}