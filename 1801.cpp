#include<cstdio>
int ab[15][15],t[15];
void init() {
	ab[0][0]=0;
	t[0]=1;

	ab[1][0]=1;
	t[1]=1;

	ab[2][0]=6;
	ab[2][1]=2;
	ab[2][2]=4;
	ab[2][3]=8;
	t[2]=4;

	ab[3][0]=1;
	ab[3][1]=3;
	ab[3][2]=9;
	ab[3][3]=7;
	t[3]=4;

	ab[4][0]=6;
	ab[4][1]=4;
	t[4]=2;

	ab[5][0]=5;
	t[5]=1;

	ab[6][0]=6;
	t[6]=1;

	ab[7][0]=1;
	ab[7][1]=7;
	ab[7][2]=9;
	ab[7][3]=3;
	t[7]=4;

	ab[8][0]=6;
	ab[8][1]=8;
	ab[8][2]=4;
	ab[8][3]=2;
	t[8]=4;

	ab[9][0]=1;
	ab[9][1]=9;
	t[9]=2;
	return;
}
int main() {
//	freopen("1801.in","r",stdin);
//	freopen("1801a.out","w",stdout);
	long long a,b;
	init();
	while(scanf("%lld%lld",&a,&b)!=EOF) {
		if(b==0) {
			printf("1\n");
			continue;
		}
		a%=10;
		printf("%d\n",ab[a][b%t[a]]);
	}
	return 0;
}
