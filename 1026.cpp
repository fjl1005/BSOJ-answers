#include<cstdio>
int a[1005],s;
void swap(int &a,int &b) {
	int t;
	t=a;
	a=b;
	b=t;
}
int main() {
	int a[10000];
	int n, i, j, r, t;
	scanf("%d",&n);
	for (i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	r = 0;
	for (i=n-1; i>0; i--) {
		for (j=1; j<=i; j++) {
			if (a[j] < a[j-1]) {
				t = a[j];
				a[j] = a[j-1];
				a[j-1] = t;
				r++;
			}
		}
	}
	printf("%d",r);
	return 0;
}