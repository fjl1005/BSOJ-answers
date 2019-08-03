#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 10000;
bool a[maxn],b[maxn],c[maxn];

void add(bool a,bool b,bool Cin,bool &Cout,bool &s){
	Cout=(a&b)|((a^b)&Cin);s=a^b^Cin;
}

int main(){
	ll n=0,m=0,k,l;
	scanf("%lld%lld",&k,&l);
	while(k){a[n++]=k%2;k/=2;}
	while(l){b[m++]=l%2;l/=2;}
	
//	for(ll i=0;i<n;i++)printf("%d",a[i]);puts("");
//	for(ll i=0;i<m;i++)printf("%d",b[i]);puts("");
	
//	printf("%lld %lld\n",n,m);
	ll p=max(n,m);
	for(ll i=0;i<p;i++)add(a[i],b[i],c[i],c[i+1],c[i]);
	if(c[p])p++;
	ll sum=0;for(ll i=0;i<p;i++)sum+=c[i]*(ll)pow(2,i);
	printf("%lld\n",sum);
	return 0;
}
