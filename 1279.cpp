#include<cstdio>
int c[500001],n;
char a[2];
int k,m,p,i;
int query(int x)
{
	int sum=0;
	while(x)
	{
		sum+=c[x];
		x-=x&-x;
	}
	return sum;
}
void update(int x,int delta)
{
	while(x<=n)
	{
		c[x]+=delta;
		x+=x&-x;
	}
}
int main()
{
	scanf("%d%d",&n,&k);
 	for(i=1;i<=k;i++)
 	{
	 	scanf("%s",&a);
		if(a[0]=='A')
		{
			scanf("%d",&m);
			int ans=query(m);
			printf("%d\n",ans);
		}	 	
		if(a[0]=='B')
		{
			scanf("%d%d",&m,&p);
			update(m,p);
		}
		if(a[0]=='C')
		{
			scanf("%d%d",&m,&p);
			update(m,-p);
		}
 	}
}