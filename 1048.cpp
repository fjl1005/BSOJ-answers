#include<cstdio>
#include<algorithm>
bool book[10005];
inline void swap(int &a,int &b){
	int t;
	t=a;
	a=b;
	b=t;
	return;
}
int main(){
	int n,m,i,j,tx,ty;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&tx,&ty);
		if(tx>ty){
			swap(tx,ty);
		}
		for(j=tx;j<=ty;j++){
			book[j]=true;
		}
	}
	int s=0;
	for(i=0;i<=n;i++){
		if(!book[i]){
			s++;
		}
	}
	printf("%d",s);
	return 0;
}