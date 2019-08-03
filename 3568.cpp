#include<cstdio>
int s[50005],t[50005],R[100005],L[100005];
bool f[50005],ch[50005];
void move(int n) {
	int ss=s[n],tt=t[n];
	R[L[ss]]=R[ss];
	L[R[ss]]=L[ss];
	if(!f[n]) {
		tt=L[tt];
	}
	R[ss]=R[tt];
	L[R[tt]]=ss;
	R[tt]=ss;
	L[ss]=tt;
	return ;
}
int main() {
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,m,i;
	char x;
	scanf("%d%d",&n,&m);
	R[0]=1;
	for(i=0; i<=n; i++) {
		R[i]=i+1;
		L[i]=i-1;
	}
	for(i=0; i<m; i++) {
		while(x=getchar()) {
			if(x=='A'||x=='B') {
				break;
			}
		}
		scanf("%d%d",&s[i],&t[i]);
		if(s[i]==t[i]) {
			ch[i]=1;
			continue;
		}
		if(x=='A') {
			f[i]=0;
		}
		if(x=='B') {
			f[i]=1;
		}
	}
	for(i=0; i<m; i++) {
		if(!ch[i]) {
			move(i);
		}
	}
	int temp=R[0];
	for(i=0; i<n; i++) {
		printf("%d\n",temp);
		temp=R[temp];
	}
	return 0;
}