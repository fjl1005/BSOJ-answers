#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n>=86) 
		cout<<"VERY GOOD";
	else if(n>=60)
		cout<<"GOOD";
	else
		cout<<"BAD";
	return 0;
}
