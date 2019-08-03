#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
char a[105];
bool camp(char a,char b){
	return a>b;
}
int main(){
	gets(a);
	int len=strlen(a);
	sort(a,a+len,camp);
	puts(a);
	return 0;
}
