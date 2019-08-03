#include<cstdio>
#define Mod 10000
int n;
int a[3005];
int dp[3005];
int time[3005];
void lis(){
	for(int i=1;i<=n;i++){
		dp[i]=1;
		time[i]=1;
	}
//	time[1]=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				time[j]=0;
			}
			if(dp[i]>=dp[j]&&a[i]>a[j]){
				dp[j]=dp[i]+1;
				time[j]=time[i]%Mod;
			}else{
				if(dp[i]+1==dp[j]){
					time[j]=(time[j]+time[i])%Mod;
				}
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	if(n==1){
		printf("1 1");
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	lis();
	int Max=-1,ans;
	for(int i=1;i<=n;i++){
		if(dp[i]>Max){
			Max=dp[i];
			ans=time[i]%Mod;
		}else{
			if(dp[i]==Max){
				ans=(ans+time[i])%Mod;
			}
		}
//		printf("%d %d %d\n",a[i],dp[i],time[i]);
	}
	printf("%d %d",Max,ans);
	return 0;
}
