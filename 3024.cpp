#include <cstdio>
#include <stack>
using namespace std;
stack<int> s;
int h[1000005],v[1000005],ans[1000005],n,anss;
void pushs(int x) {
	while(!s.empty()&&h[x]>=h[s.top()]) {
		s.pop();
	}
	if(!s.empty()) {
		ans[s.top()]+=v[x];
	}
	s.push(x);
	return ;
}
int main() {
	int i;
	scanf("%d",&n);
	for (i=1; i<=n; i++) {
		scanf("%d%d",&h[i],&v[i]);
	}
	for (i=1; i<=n; i++) {
		pushs(i);
	}
	while (!s.empty()) {
		s.pop();
	}
	for (i=n; i>=1; i--) {
		pushs(i);
	}
	for (i=1; i<=n; i++) {
		anss=max(ans[i],anss);
	}
	printf("%d",anss);
	return 0;
}