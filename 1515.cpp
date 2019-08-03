#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
	const double pi=3.1415926;
	double r,c,s;
	cin>>r;
	c=2*pi*r;
	s=r*r*pi;
	printf("%.2lf %.2lf",c,s);
	return 0;
}