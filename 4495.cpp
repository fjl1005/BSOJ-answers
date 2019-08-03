#include<iostream>
using namespace std;
int a[110],b[110],n,i,j;
int main() 
{
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
	{
		a[i]=a[i]*(i+1);
	}
	for(i=n-1;i>0;i--)
	{
		a[i]=a[i]-a[i-1];
	}
	for(i=0;i<n;i++)
	{
		if(i!=n-1) cout<<a[i]<<' ';
		else cout<<a[i];
	}
    return 0;
}