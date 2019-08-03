#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
queue<int> Q;
const int N=25;
int R[N],W[N],dis[N],map[N][N],times[N];
bool go[N][N],in[N];
bool SPFA(int x) {
	int tmp;
	memset(dis,127,sizeof(dis));
	memset(times,0,sizeof(times));
	memset(map,0,sizeof(map));
	memset(in,0,sizeof(in));
	dis[24]=0;
	times[24]=1;
	for(int i=8; i<=24; i++) map[i][i-8]=-R[i];
	for(int i=1; i<=7; i++) map[i][i+16]=x-R[i];
	for(int i=1; i<=24; i++) map[i-1][i]=W[i];
	map[24][0]=-x;
	Q.push(24);
	while(!Q.empty()) {
		tmp=Q.front();
		in[tmp]=0;
		Q.pop();
		for(int i=0; i<=24; i++) if(go[tmp][i]&&dis[i]>dis[tmp]+map[tmp][i]) {
				dis[i]=dis[tmp]+map[tmp][i];
				times[i]++;
				if(!in[i]) {
					in[i]=1;
					Q.push(i);
				}
				if(times[i]>25) return false;
			}
	}
	return (dis[0]==-x);
}
int main() {
	int lower,upper,t,n,x,mid;
	bool flag;
	for(int i=8; i<=24; i++) go[i][i-8]=1;
	for(int i=1; i<=7; i++) go[i][i+16]=1;
	for(int i=1; i<=24; i++) go[i][i-1]=go[i-1][i]=1;
	go[24][0]=1;
	memset(W,0,sizeof(W));
	for(int i=1; i<=24; i++) scanf("%d",&R[i]);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&x);
		W[x+1]++;
	}
	lower=1;
	upper=n;
	flag=false;
	while(lower<=upper) {
		mid=(lower+upper)>>1;
		if(SPFA(mid)) {
			flag=true;
			upper=mid-1;
		} else lower=mid+1;
	}
	if(!flag) printf("No Solution!\n");
	else printf("%d\n",lower);
}