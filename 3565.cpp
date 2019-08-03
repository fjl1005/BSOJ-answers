#include<cstdio>
int a[105];
int main() {
//	freopen("bank.in","r",stdin);
//	freopen("bank.out","w",stdout);
	char x,front=0,rear=0;
	int n;
	while(scanf("%c",&x)!=EOF) {
		if(x=='O') {
			getchar();
			if(front==rear) {
				printf("None\n");
				continue;
			}
			printf("%d\n",a[front]);
			front++;
			continue;
		}
		if(x=='I') {
			scanf("%d",&n);
			getchar();
			a[rear]=n;
			rear++;
			continue;
		}
	}
	return 0;
}