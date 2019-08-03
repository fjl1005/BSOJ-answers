#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005];
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}