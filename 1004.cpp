#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int F[1005];
int f(int x){
	int s=0,i;
	if(x==0)
		return 0;
	for(i=1;i<=x/2;i++){
		if(F[i]==0)
			F[i]=f(i);
		s+=F[i];
	}
	return s+1;
}
int main(){
	int n;
	cin>>n;
	cout<<f(n);
	return 0;
}