#include<cstdio>
#include<algorithm>
using namespace std;
struct f {
	int s,e,c;
} a[30005];
int cmp(f a,f b) {
	return a.s<b.s;
}
int t[30005];
int main() {
	int n,i,j,Max=0;
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		scanf("%d%d%d",&a[i].s,&a[i].e,&a[i].c);
	}
	sort(a+1,a+n+1,cmp);
	for(i=n;i>0;i--){
		t[i]=a[i].c;
		for(j=i+1;j<=n;j++){
			if(a[i].e<=a[j].s&&t[j]+a[i].c>t[i]){
				t[i]=t[j]+a[i].c;
			}
		}
		if(t[i]>Max){
			Max=t[i];
		}
	}
	printf("%d",Max);
	return 0;
}