#include<cstdio>
int a[105],l[105],r[105],f[105];
void dfs(int root){
	int i;
	if(l[root]!=0){
		dfs(l[root]);
	}
	printf("%d\n",root);
	if(r[root]!=0){
		dfs(r[root]);
	}
	return ;
}
int main(){
	int n,i,x,y,z,root;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		a[x]=x;
		l[x]=y;
		r[x]=z;
		f[y]=f[z]=x;
	}
	for(i=1;i<=n;i++){
		if(f[i]==0){
			root=i;
			break;
		}
	}
	dfs(root);
	return 0;
}