#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(a<b)
		a=b;
	if(a<c)
		a=c;
	cout<<a;
	return 0;
}
