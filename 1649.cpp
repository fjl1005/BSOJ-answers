#include<cstdio>
#include<algorithm>
using namespace std;
struct f{
	int b,e;
}a[1005];
int cmp(f a,f b){
	if(a.e!=b.e){
		return a.e<b.e;
	}
	return a.b<b.b;
}
int main() {
	int n,i,s=0,t=-1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&a[i].b,&a[i].e);
	}
	sort(a,a+n,cmp);
	for(i=0;i<n;i++) {
		if(a[i].b>=t) {
			s++;
			t=a[i].e;
		}
	}
	printf("%d",s);
	return 0;
}