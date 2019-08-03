#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const int mod=100003;
long long power(long long a,long long n,long long b) {
	long long t;
	if(n==0)
		return 1%b;
	if(n==1)
		return a%b;
	t=power(a,n/2,b);
	t=t*t%b;
	if((n%2)==1)
		t=t*a%b;
	return t;
}
int main() {
	long long n,m;
	cin>>m>>n;
	long long ans=(power(m,n,mod)+mod-m*power(m-1,n-1,mod)%mod)%mod;
	cout<<ans;
	return 0;
}