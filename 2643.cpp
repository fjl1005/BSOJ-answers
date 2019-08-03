#include<cstdio>
#include<algorithm>
using std::sort;
struct f{
	int name,score;
}a[5005];
int cmp(const f a,const f b){
	if(a.score<b.score){
		return 0;
	}
	if(a.score>b.score){
		return 1;
	}
	if(a.name<b.name){
		return 1;
	}
	return 0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n,m;
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a[i].name,&a[i].score);
	}
	sort(a+1,a+n+1,cmp);
	int t=(int)((double)m*1.5);
	printf("%d ",a[t].score);
	for(;a[t].score==a[t+1].score;t++);
//	t--;
	printf("%d\n",t);
	for(i=1;i<=t;i++){
		printf("%d %d\n",a[i].name,a[i].score);
	}
	return 0;
}
