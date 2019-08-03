#include<cstdio>
int book[205];
struct f {
	int x;
	int s;
} t[2055];
bool m[2055];
int main() {
	int n,a,b,i,head=1,tail=2;
	scanf("%d%d%d",&n,&a,&b);
	if(a==b) {
		printf("0");
		return 0;
	}
	for(i=1; i<=n; i++) {
		scanf("%d",&book[i]);
	}
	t[1].x=a;
	t[1].s=0;
	m[a]=1;
	bool flag=1;
	while(head<=tail) {
		if(t[head].x>0&&t[head].x<=n) {
			if(t[head].x+book[t[head].x]<=n) {
				if(!m[t[head].x+book[t[head].x]]) {
					t[tail].s=t[head].s+1;
					t[tail].x=t[head].x+book[t[head].x];
					m[t[tail].x]=1;
					if(t[tail].x==b) {
						printf("%d",t[tail].s);
						flag=0;
						break;
					}
					tail++;
				}
			}
			if(t[head].x-book[t[head].x]>0) {
				if(!m[t[head].x-book[t[head].x]]) {
					t[tail].s=t[head].s+1;
					t[tail].x=t[head].x-book[t[head].x];
					m[t[tail].x]=1;
					if(t[tail].x==b) {
						printf("%d",t[tail].s);
						flag=0;
						break;
					}
					tail++;
				}
			}
		}
		head++;
	}
	if(flag){
		printf("-1");
	}
	return 0;
}