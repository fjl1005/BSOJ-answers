#include<cstdio>
int a[1000005];
int main() {
	int n;
	scanf("%d",&n);
	int s=0;
	for(int i=1; i<=n; i++) {
		int k;
		scanf("%d",&k);
		for(int j=1; j<=k; j++) {
			int t;
			scanf("%d",&t);
			a[t]++;
		}
		int j;
		for(j=0;;j++){
			if(a[j]){
				a[j]--;
				break;
			}
		}
		s-=j;
		for(j=1000000;;j--){
			if(a[j]){
				a[j]--;
				break;
			}
		}
		s+=j;
	}
	printf("%d",s);
	return 0;
}
/*
2
5 3 1 2 1 5
8 18 20 6 9 3 7 50 42

1 1 2 3 5
3 6 7 8 9 18 20 42 50

1+1+5+50

*/