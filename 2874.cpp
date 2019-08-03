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
inline bool read(int &num)    
{  
        char in;bool IsN=false;  
        in=getchar();  
        if(in==EOF) return false;  
        while(in!='-'&&(in<'0'||in>'9')) in=getchar();  
        if(in=='-'){ IsN=true;num=0;}  
        else num=in-'0';  
        while(in=getchar(),in>='0'&&in<='9'){  
                num*=10,num+=in-'0';  
        }  
        if(IsN) num=-num;  
        return true;  
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int i;
	for(i=1; i<=n; ++i) {
		first[i]=-1;
	}
	for(i=1; i<=m; ++i) {
		scanf("%d%d",&u[i],&v[i]);
		next[i]=first[u[i]];
		first[u[i]]=i;
		++gragh[v[i]];
	}
	for(i=1; i<=n; ++i) {
		if(gragh[i]==0) {
			goto start;
		}
	}
	printf("no solution");
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
		int b=first[t];
		while(b!=-1) {
			--gragh[v[b]];
			if(gragh[v[b]]==0&&book[v[b]]==0) {
				q.push(v[b]);
				book[v[b]]=1;
			}
			b=next[b];
		}
		ttt[++top]=t;
		sum++;
	}
//	for(i=1;i<=n;i++){
//		if(book[i]==0){
//
//		}
//	}
	if(sum!=n) {
		printf("no solution");
	} else {
		for(i=1; i<=top; i++) {
			printf("%d ",ttt[i]);
		}
	}
	return 0;
}