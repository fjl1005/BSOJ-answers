#include<cstdio>
int f[30005],a[30005],n,m;
int find(int t) {
	if(f[t]==t) {
		return t;
	}
	f[t]=find(f[t]);
	return f[t];
}
void merge(int x,int y) {
	int tx,ty;
	tx=find(x);
	ty=find(y);
	if(tx==ty) {
		return ;
	}
	f[ty]=tx;
	return ;
}
int main() {
	int i,x,y,s=0,Max=-1;
	scanf("%d%d",&n,&m);
	for(i=1; i<=n; i++) {
		f[i]=i;
	}
	for(i=1; i<=m; i++) {
		scanf("%d%d",&x,&y);
		merge(x,y);
	}
	for(i=1;i<=n;i++){
		int t=find(i);
		a[t]++;
		if(a[t]>Max){
			Max=a[t];
		}
	}
	printf("%d",Max);
	return 0;
}