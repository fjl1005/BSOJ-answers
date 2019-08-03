#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k,p,q;
string a[105],b[105],ans[105];
string t,h;
int main() {
	int i,j;
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		cin>>t>>h;
		if(h=="UP")
			b[q++]=t;
		else if(h=="SAME")
			ans[i]=t;
		else
			a[p++]=t;
	}
	int t1=0,t2=0;
	for(i=1; i<=n; i++) {
		if(ans[i]=="") {
			if(t1<p)
				ans[i]=a[t1++];
			else
				ans[i]=b[t2++];
		}
	}
	for(i=1; i<=n; i++)
		cout<<ans[i]<<endl;
	return 0;
}