#include<bits/stdc++.h>
using namespace std;
#define lc(x) (x<<1)
#define rc(x) (x<<1^1)
#define sq(x) ((x)*(x))
#define ll int
ll n,d,k,m;ll ans[11];
struct point{ll x[5],minx[5],maxx[5];}p[100001],a[500001],cur,tag[11];
bool operator <(const point &a,const point &b){return a.x[d]<b.x[d];}
void build(ll v,ll l,ll r,ll dep){
	d=dep%k;ll mid=(l+r)>>1;
	nth_element(p+l,p+mid,p+r+1);a[v]=p[mid];
	if(l<=mid-1)build(lc(v),l,mid-1,dep+1);
	if(r>=mid+1)build(rc(v),mid+1,r,dep+1);
}
//ll sq(ll x){return x*x;}
ll dis(point a,point b){
	ll sum=0;for(ll i=0;i<k;i++)sum+=sq(a.x[i]-b.x[i]);return sum;
}
void cal(point a){
	ll k=dis(a,cur);
	for(ll i=1;i<=m;i++)
		if(k<ans[i]){
			for(ll j=m;j>=i+1;j--){ans[j]=ans[j-1];tag[j]=tag[j-1];}
			ans[i]=k;tag[i]=a;
			break;
		}
}
void query(ll v,ll l,ll r,ll dep){
	d=dep%k;cal(a[v]);ll mid=(l+r)>>1;
	if(cur<a[v]){
		if(l<=mid-1)query(lc(v),l,mid-1,dep+1);d=dep%k;
		if(r>=mid+1&&sq(a[v].x[d]-cur.x[d])<=ans[m])query(rc(v),mid+1,r,dep+1);
	}else{
		if(r>=mid+1)query(rc(v),mid+1,r,dep+1);d=dep%k;
		if(l<=mid-1&&sq(a[v].x[d]-cur.x[d])<=ans[m])query(lc(v),l,mid-1,dep+1);
	}
}
int main(){
	ll t;
   	while(scanf("%d%d",&n,&k)!=EOF){
		for(ll i=1;i<=n;i++)
			for(ll j=0;j<k;j++)
				scanf("%d",&p[i].x[j]);
		build(1,1,n,0);
		scanf("%d",&t);
		for(ll T=1;T<=t;T++){
			for(ll i=0;i<k;i++)scanf("%d",&cur.x[i]);
		scanf("%d",&m);
		for(ll i=1;i<=m;i++)ans[i]=1<<30;
		query(1,1,n,0);
		printf("the closest %d points are:\n",m);
		for(ll i=1;i<=m;i++,puts(""))
			for(ll j=0;j<k;j++)
				printf("%d ",tag[i].x[j]);
		}
	} 
	return 0;
}
/**/