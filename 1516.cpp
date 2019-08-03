#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
	char a[10];
	int i;
	for(i=0;i<4;i++){
		cin>>a[i];
	}
	for(i=3;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}