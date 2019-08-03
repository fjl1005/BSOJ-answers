#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int N=100005,M=N*25;
int L[M],R[M];
int n,m,c[M],a[N];
int root[N],tot,ntot;
vector<int> Li,Ri,ert;
int Qtype[N],Qx[N],Qy[N],Qk[N];
#define lowbit(x) ((x)&-(x))
int Build(int l,int r) {
	int rt=++tot;
	if (l==r) {
		c[rt]=0;
		return rt;
	}
	int mid=(l+r)>>1;
	L[rt]=Build(l,mid);
	R[rt]=Build(mid+1,r);
	return rt;
}
int Change(int p,int l,int r,int x,int v) {
	int rt=++tot;L[rt]=L[p];R[rt]=R[p];c[rt]=c[p];
	if (l==r) {
		c[rt]+=v;
		return rt;
	}
	int mid=(l+r)>>1;
	if (x<=mid) L[rt]=Change(L[p],l,mid,x,v);
	else R[rt]=Change(R[p],mid+1,r,x,v);
	c[rt]=c[L[rt]]+c[R[rt]];
	return rt;
}
void Need(int x,vector<int>& v) {
	while (x) {
		v.push_back(root[x]);
		x-=lowbit(x);
	}
}
void BecomeL(vector<int>& v) {
	for (int i=0;i<v.size();i++) v[i]=L[v[i]];
}
void BecomeR(vector<int>& v) {
	for (int i=0;i<v.size();i++) v[i]=R[v[i]];
}
int Ask(int l,int r,int k) {
	if (l==r) return l;
	int suml=0,sumr=0;
	for (int i=0;i<Li.size();i++) suml+=c[L[Li[i]]];
	for (int i=0;i<Ri.size();i++) sumr+=c[L[Ri[i]]];
	int minus=sumr-suml;
	int mid=(l+r)>>1;
	if (minus>=k) {
		BecomeL(Li);
		BecomeL(Ri);
		return Ask(l,mid,k);
	} else {
		BecomeR(Li);
		BecomeR(Ri);
		return Ask(mid+1,r,k-minus);
	}
}
void Updata(int x,int v,int dt) {
	while (x<=n) {
		root[x]=Change(root[x],1,ntot,v,dt);
		x+=lowbit(x);
	}
}
int GetNum(int val) {
	int t=lower_bound(ert.begin(),ert.end(),val)-ert.begin();
	return t+1;
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		ert.push_back(a[i]);
	}
	while (getchar()!='\n');
	for (int i=1;i<=m;i++) {
		int x,y,k;
		char op[10];
		scanf("%s%d%d",op,&x,&y);
		if (op[0]=='C') {
			Qtype[i]=1;
			Qx[i]=x;
			Qy[i]=y;
			ert.push_back(y);
		} else {
			scanf("%d",&k);
			Qtype[i]=0;
			Qx[i]=x;
			Qy[i]=y;
			Qk[i]=k;
		}
	}
	sort(ert.begin(),ert.end());
	vector<int>::iterator it=unique(ert.begin(),ert.end());
	ert.erase(it,ert.end());
	ntot=ert.size();
	root[0]=Build(1,ntot);
	for (int i=1;i<=n;i++)
		Updata(i,GetNum(a[i]),1);
	for (int i=1;i<=m;i++) {
		int x,y,k;
		x=Qx[i];y=Qy[i];k=Qk[i];
		if (Qtype[i]) {
			Updata(x,GetNum(a[x]),-1);
			a[x]=y;
			Updata(x,GetNum(a[x]),1);
		} else {
			Li.clear();
			Ri.clear();
			Need(x-1,Li);
			Need(y,Ri);
			printf("%d\n",ert[Ask(1,ntot,k)-1]);
		}
	}
	return 0;
}