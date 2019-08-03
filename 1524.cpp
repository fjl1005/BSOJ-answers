#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
bool camp(int a,int b){
	return a>b;
}
int main(){
	int a[10],i;
	for(i=0;i<3;i++){
		cin>>a[i];
	}
	sort(a,a+3,camp);
	cout<<a[0]<<' '<<a[1]<<' '<<a[2];
	return 0;
}
