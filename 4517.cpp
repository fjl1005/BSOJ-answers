//#include<algorithm>
//#include<cmath>
//#include<cstdlib>
//#include<cstring>
//#include<ctime>
//#include<deque>
//#include<map>
//#include<iostream>
//#include<queue>
//#include<set>
//#include<stack>
//using namespace std;

#include<cstdio>

#define inf 1<<30
inline int Max(int a,int b) {
	return a>b?a:b;
}
inline int Min(int a,int b) {
	return a<b?a:b;
}
inline int Abs(int x) {
	return x<0?-x:x;
}
inline void Swap(int &a,int &b) {
	a^=b^=a^=b;
}

int n;
int a[55][55];

int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	int k,kx,ky;
	k=1;
	kx=1;
	ky=(1+n)/2;
	a[kx][ky]=k;
	for(int i=2; i<=n*n; i++) {
		if(kx==1&&ky!=n) {
			kx=n;
			ky=ky+1;
//			printf("1\n");
		} else {
			if(kx!=1&&ky==n) {
				kx=kx-1;
				ky=1;
//				printf("2\n");
			} else {
				if(kx==1&&ky==n) {
					kx=kx+1;
					ky=ky;
//					printf("3\n");
				} else {
					if(a[kx-1][ky+1]==0) {
						kx=kx-1;
						ky=ky+1;
//						printf("4\n");
					} else {
						kx=kx+1;
						ky=ky;
//						printf("5\n");
					}
				}
			}
//			for(int i=1; i<=n; i++) {
//				for(int j=1; j<=n; j++) {
//					printf("%d ",a[i][j]);
//				}
//				puts("");
//			}
//			puts("");
		}
//		printf("%d ",k);
		k++;
		a[kx][ky]=k;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			printf("%d ",a[i][j]);
		}
		puts("");
	}
	return 0;
}

