#include<cstdio>
#include<algorithm>
using std::sort;
struct mt{
	int u,v,c;
}tree[90005];
int n,m;
int cmp(mt a,mt b){
	if(a.c<b.c){
		return 1;
	}
	if(a.c>b.c){
		return 0;
	}
	if(a.u<b.u){
		return 1;
	}
	if(a.u>b.u){
		return 0;
	}
	return a.v>b.v;
}
int f[305];
int getf(int v){
	if(f[v]==v){
		return f[v];
	}
	f[v]=getf(f[v]);
	return f[v];
}
int merge(int v,int u){
	int tv,tu;
	tv=getf(v);
	tu=getf(u);
	if(tv!=tu){
		f[tu]=tv;
		return 1;
	}
	return 0;
}
void init(int n){
	int i;
	for(i=1;i<=n;i++){
		f[i]=i;
	}
	return;
}
int main(){
	int i;
	scanf("%d%d",&n,&m);
	init(n);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&tree[i].u,&tree[i].v,&tree[i].c);
	}
	sort(tree+1,tree+m+1,cmp);
	int sum=0,count=0;
	for(i=1;i<=m;i++){
		if(merge(tree[i].u,tree[i].v)){
			sum+=tree[i].c;
			count++;
		}
		if(count==n-1){
			break;
		}
	}
	printf("%d",sum);
	return 0;
}