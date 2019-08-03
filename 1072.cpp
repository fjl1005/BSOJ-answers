#include<cstdio>
long long a[1005][1005]={0};
int main() {
	int n,m,i,j,x,y;
	scanf("%d%d",&n,&m);
	scanf("%d%d",&x,&y);
	n+=4;
	m+=4;
	x+=4;
	y+=4;
	a[x][y]=-1;
	a[x-2][y-1]=-1;
	a[x-1][y-2]=-1;
	a[x-2][y+1]=-1;
	a[x-1][y+2]=-1;
	a[x+2][y-1]=-1;
	a[x+1][y-2]=-1;
	a[x+2][y+1]=-1;
	a[x+1][y+2]=-1;
	a[4][4]=1;
	for(i=4; i<=n; i++) {
		for(j=4; j<=m; j++) {
			if(a[i][j]==-1)
				continue;
			if(a[i-1][j]>0)
				a[i][j]+=a[i-1][j];
			if(a[i][j-1]>0)
				a[i][j]+=a[i][j-1];
		}
	}
	printf("%lld",a[n][m]);
	return 0;
}