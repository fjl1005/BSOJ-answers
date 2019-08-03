#include<cstdio>
int f[5005],n,m,p;
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
	int i,x,y,s=0;
	scanf("%d%d%d",&n,&m,&p);
	for(i=1; i<=n; i++) {
		f[i]=i;
	}
	for(i=1; i<=m; i++) {
		scanf("%d%d",&x,&y);
		merge(x,y);
	}
	for(i=1; i<=p; i++) {
		scanf("%d%d",&x,&y);
		if(find(x)==find(y)){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}