#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int map[100][100]= {0},n,m,time1,sum=0;
struct pai {
	int num,x,y;
} a[10000];
int cmp(pai a,pai b) {
	if(a.num>b.num) {
		return 1;
	}
	return 0;
}
int main() {
	cin>>n>>m>>time1;
	int x=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			scanf("%d",&map[i][j]);
			if(map[i][j]!=0) {
				a[x].num=map[i][j];
				a[x].x=i;
				a[x].y=j;
				x++;
			}
		}
	}
	sort(a,a+x,cmp);
	time1=time1-a[0].x-1;
	if(time1>a[0].x) {
		sum=sum+a[0].num;
		for(int i=1; i<x; i++) {
			int chax=abs(a[i].x-a[i-1].x);
			int chay=abs(a[i].y-a[i-1].y);
			time1=time1-chax-chay-1;
			if(time1<a[i].x)break;
			sum=sum+a[i].num;
		}
	}
	cout<<sum;
	return 0;
}