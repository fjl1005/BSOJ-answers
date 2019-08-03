#include<cstdio>
#include<algorithm>
using namespace std;

int p[55];

int n;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		getchar();
		getchar();
		for(int j=1;j<=n;j++){
			char ch=getchar();if(ch=='-')continue;
			if(ch=='W')p[i]+=3;
			if(ch=='L')p[j]+=3;
			if(ch=='D')p[i]++,p[j]++;
		}
	}
	int maxx=0;
	for(int i=1;i<=n;i++)if(maxx<p[i])maxx=p[i];
	for(int i=1;i<=n;i++)if(maxx==p[i])printf("%d ",i);
	return 0;
}
/*
3
-WW
W-W
WW-

5
-DWWD
L-WLL
DD-WD
DDL-L
DDLL-
*/