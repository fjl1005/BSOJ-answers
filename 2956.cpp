#include<cstdio>

char p[400005];
int next[400005],len;

void getnext(){
	int i=0,j=-1;
	next[0]=-1;
	while(p[i]){
		if(j==-1||p[i]==p[j]){
			++i,++j;
			next[i]=j;
		}else{
			j=next[j];
		}
	}
	len=i;
}

void out(int n){
	if(next[n]==0){
		return;
	}
	out(next[n]);
	printf("%d ",next[n]);
}

int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	while(scanf("%s",p)==1){
		getnext();
		out(len);
		printf("%d\n",len);
	}
	return 0;
}
