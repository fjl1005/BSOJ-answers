#include<cstdio>
#include<algorithm>
using namespace std;
int a[1008600],s=1;
int main() {
	int n,i;
	scanf("%d",&n);
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(i=0; i<n; i++) {
		if(a[i]==a[i+1])
			s++;
		else {
			printf("%d %d\n",a[i],s);
			s=1;
		}
	}
	return 0;
}