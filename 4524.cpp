#include<iostream>
using namespace std;
int i,j,n,m,s;
char a[105][105];
int main() {
	cin>>n>>m;
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
			cin>>a[i][j];
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++) {
			if(a[i][j]=='?') {
				if(a[i+1][j]=='*')s++;
				if(a[i-1][j]=='*')s++;
				if(a[i][j-1]=='*')s++;
				if(a[i][j+1]=='*')s++;
				if(a[i+1][j+1]=='*')s++;
				if(a[i-1][j-1]=='*')s++;
				if(a[i+1][j-1]=='*')s++;
				if(a[i-1][j+1]=='*')s++;
				a[i][j]=s+48;
			}
			s=0;
		}
	for(i=1; i<=n; i++) {
		for(j=1; j<=m; j++)
			cout<<a[i][j];
		cout<<endl;
	}

	return 0;
}