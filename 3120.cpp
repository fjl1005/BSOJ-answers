#include<cstdio>
#include<algorithm>
using namespace std;
int l,t,n;
struct q {
	int x;
	char ch;
} a[70005];
int cmp(q a,q b) {
	return a.x<=b.x;
}
int main() {
	scanf("%d%d%d",&l,&t,&n);
	for(int i=1; i<=n; i++) {
		scanf("%d %c",&a[i].x,&a[i].ch);
		if(a[i].ch=='D') {
			a[i].x+=t;
			a[i].x%=2*l;
			if(a[i].x>=l) {
				a[i].x=2*l-a[i].x;
			}
		} else {
			if(t>=a[i].x) {
				a[i].x=t-a[i].x;
				a[i].x%=2*l;
				if(a[i].x>=l) {
					a[i].x=2*l-a[i].x;
				}
			} else {
				a[i].x=a[i].x-t;
			}
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; i++) {
		printf("%d ",a[i].x);
	}
	return 0;
}
