#include<iostream>
using namespace std;
int a[100001],n,m;
bool check(int maxx) {
	int i,sum=0,dd=0;
	for(i=1; i<=n; i++)
		if(sum+a[i]<=maxx)sum+=a[i];
		else {
			dd++;
			sum=a[i];
			if(sum>maxx)
				return 0;
		}
	dd++;
	if(dd<=m)
		return 1;
	else
		return 0;
}
int main() {
	int R=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		R+=a[i];
	}
	int L=0;
	while(L<R) {
		int mid=(L+R)/2;
		if(check(mid))
			R=mid;
		else
			L=mid+1;
	}
	cout<<L<<endl;
	return 0;
}