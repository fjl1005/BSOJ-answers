#include<cstdio>
#include<cmath>
int a[45],n,mx;
bool vis[45][1600][800];
double ans=-1;
double S(int x,int y,int z) {
	if (x>y+z||y>x+z||z>x+y) {
		return -1;
	}
	double p=(double)(x+y+z)/2;
	return sqrt(p*(p-x)*(p-y)*(p-z));
}
double max(double a,double b) {
	return a>b?a:b;
}
void swap(int &x,int &y) {
	x^=y^=x^=y;
	return;
}
void dfs(int p,int x,int y,int z) {
	int i,j;
	if (p>mx) {
		ans=max(ans,S(x,y,z));
		return;
	}
	if (x<y) {
		swap(x,y);
	}
	if (x<z) {
		swap(x,z);
	}
	if (y<z) {
		swap(y,z);
	}
	if (vis[p][x][y]) {
		return;
	}
	vis[p][x][y]=1;
	for (i=0; i<=a[p]; i++) {
		for (j=0; i+j<=a[p]; j++) {
			dfs(p+1,x+i*p,y+j*p,z+(a[p]-i-j)*p);
		}
	}
	return;
}
int main() {
	int i,j,k,p,q,x,y,z;
	scanf("%d",&n);
	for (i=1; i<=n; i++) {
		scanf("%d",&x);
		mx=max(x,mx);
		a[x]++;
	}
	dfs(1,0,0,0);
	if (ans<0) {
		printf("-1");
	} else {
		printf("%d",(int)(ans*100));
	}
}