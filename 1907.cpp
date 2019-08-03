/*
  Name: fujunlin
  Copyright: fujunlin
  Author: fujunlin
  Date: 10-07-17 19:37
  Description: 原本以为这可以用一个二维数组来实现动态
  规划，但n,m的范围太大，估计空间时间都得超，后来发现
  这道题是最长不降子序列问题
*/
#include <cstdio>
#include <cmath> 
#include <algorithm>
using namespace std;
struct f{
	int x;
	int y;
}s[1010];
int dp[1010];
int cmp(f a,f b){
	if(!(a.x==b.x)){
		return a.x<b.x;
	}
	return a.y<b.y;
}
int max(int a,int b){
    return a>b?a:b;
}
int main(){
	int n,m,k,i,j,Max;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=k;i++){
		dp[i]=1;
	}
	Max=-1;
	dp[1]=1;
	for(i=1;i<=k;i++){
		scanf("%d%d",&s[i].x,&s[i].y);
	}
	sort(s+1,s+k+1,cmp);
	for(i=2;i<=k;i++){
		for(j=1;j<i;j++){
			if(s[i].x>s[j].x&&s[i].y>s[j].y){
				dp[i]=max(dp[j]+1, dp[i]);
			}
		}
		Max=max(Max, dp[i]);
	}
	printf("%d",(int)(100*((sqrt(2)-2)*Max+m+n)+0.5));
	return 0;
}
