#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
	int x;
	cin>>x;
	if(x>0)
		cout<<x+1;
	if(x<0)
		cout<<x-1;
	if(x==0)
		cout<<0;
	return 0;
}