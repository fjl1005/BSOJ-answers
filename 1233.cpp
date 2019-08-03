#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,a[50005],b[50005],tot,va[50005],C[50005],s[50005], ans[50];
long long lowbit(long long x)
{
	return x&(-x);
}
long long Sub(long long x)
{
	long long Ans=0;
	for(int i=x;i>0;i-=lowbit(i))Ans+=C[i];
	return Ans;
}
void Add(long long x,long long y)
{
	for(long long i=x;i<=50000;i+=lowbit(i))C[i]+=y;
}
void Qadd(long long x[],long long y)
{
	x[1]+=y;
	for(int i=1;i<=x[0];i++)
	{
		x[i+1]+=x[i]/10;
		x[i]%=10;
	}
	if(x[x[0]+1])x[0]++;
}
int main()
{
	ans[0]=1;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=a[i];
		s[i]=1;
	}
	sort(b+1,b+n+1);
	tot=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)
	va[i]=lower_bound(b+1,b+n+1,a[i])-b;
	for(int t=2;t<=5;t++)
	{
		memset(C,0,sizeof(C));
		for(int i=1;i<=n;i++)
		{
			Add(va[i],s[i]);
			s[i]=Sub(va[i]-1);
			if(t==5)Qadd(ans,s[i]);
		}
	}
	for(int i=ans[0];i>=1;i--)printf("%lld",ans[i]);
	return 0;
}