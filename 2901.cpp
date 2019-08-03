#include<cstdio>
#include<stack>
using namespace std;
int a[100005],res[100005];
void work(int n) {
	int i=0;
	stack<int> stk;
	while (i<n) {
		if (stk.empty() || a[stk.top()]>=a[i]) {
			stk.push(i++);
		} else {
			res[stk.top()] = i+1;
			stk.pop();
		}
	}
	return ;
}
int main() {
	int n,i,x;
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	work(n);
	for(i=0; i<n; i++) {
		printf("%d ",res[i]);
	}
}