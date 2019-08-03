#include<cstdio>
#include<algorithm>
using std::sort;
struct f{
	int c,d;
}a[20005];
int cmp(f a,f b){
	return a.c<b.c;
}
int f[20005];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++){
		scanf("%d%d",&a[i].c,&a[i].d);
	}
	sort(a+1,a+n+1,cmp);
	int j;
	f[1]=1;
	int maxx=1;
	for(i=2;i<=n;i++){
		for(j=1;j<i;j++){
			if(f[i]<f[j]&&a[i].d>a[j].d){
				f[i]=f[j];
			}
		}
		f[i]++;
		if(f[i]>maxx){
			maxx=f[i];
		}
	}
	printf("%d",maxx);
	return 0;
}
