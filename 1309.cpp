#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int gragh[205];
int u[20005],v[20005],next[20005];
int first[205];
int book[205];
int ttt[205];
int top;
int main() {
	int n,m;
	scanf("%d",&n);
	int i;
	for(i=1; i<=n; ++i) {
		first[i]=-1;
	}
	for(i=1;scanf("%d%d",&u[i],&v[i])==2; ++i) {
//		scanf("%d",&u[i]);
//		scanf("%d",&v[i]);
		next[i]=first[u[i]];
		first[u[i]]=i;
		++gragh[v[i]];
//		puts("fuck");
	}
//	printf("%d",m);
//	puts("asd");
	for(i=1; i<=n; ++i) {
		if(gragh[i]==0) {
			goto start;
		}
	}
	printf("No answer");
	return 0;
start:
	;
	int head,tail;
	for(i=1; i<=n; ++i) {
		if(gragh[i]==0&&book[i]==0) {
			q.push(i);
			book[i]=1;
		}
	}
	int sum=0;
	while(!q.empty()) {
		int t=q.top();
		q.pop();
//		printf("%d ",t);
//		printf("%d ",t);
//		puts("asd");
		int b=first[t];
		while(b!=-1) {
//			puts("asd");
			--gragh[v[b]];
			if(gragh[v[b]]==0&&book[v[b]]==0) {
				q.push(v[b]);
				book[v[b]]=1;
			}
			b=next[b];
		}
		ttt[++top]=t;
//		printf("%d ",q.size());
		sum++;
	}
	
//	for(i=1;i<=n;i++){
//		if(book[i]==0){
//
//		}
//	}
	if(sum!=n) {
		printf("No answer");
	} else {
		for(i=1; i<=top; i++) {
			printf("%d ",ttt[i]);
		}
	}
	return 0;
}