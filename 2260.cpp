#include<cstdio>

inline int Max(int a,int b) {
	return a>b?a:b;
}

inline int Min(int a,int b) {
	return a<b?a:b;
}

int l,n;
int main() {
//	freopen("ff1.in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&l,&n);
	int maxx=0,minn=0;
	for(int i=1; i<=n; i++) {
		int t;
		scanf("%d",&t);
		int s1=t,s2=l-t+1;
		maxx=Max(maxx,Max(s1,s2));
		minn=Max(minn,Min(s1,s2));
	}
	printf("%d %d",minn,maxx);
	return 0;
}

