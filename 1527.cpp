#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n<100)
		cout<<10;
	else if(n<110)
		cout<<30;
	else if(n<120)
		cout<<50;
	else if(n<130)
		cout<<70;
	else
		cout<<80;
	return 0;
}
