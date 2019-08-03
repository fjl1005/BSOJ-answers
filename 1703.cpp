#include<cstdio>
int f[1005],n,m;
int find(int t){
	if(f[t]==t){
		return t;
	}
	f[t]=find(f[t]);
	return f[t];
}
void merge(int x,int y){
	int tx,ty;
	tx=find(x);
	ty=find(y);
	if(tx==ty){
		return ;
	}
	f[ty]=tx;
	return ;
}
int main(){
	int i,x,y,s=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		f[i]=i;
	}
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		merge(x,y);
	}
	for(i=1;i<=n;i++){
		if(f[i]==i){
			s++;
		}
	}
	printf("%d",s);
	return 0;
}