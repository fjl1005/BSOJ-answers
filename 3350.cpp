#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 50001;
struct Q{
	ll l,r;ll id;
	ll ans1,ans2;
}q[maxn];
ll cnt[maxn],ans1=0,ans2=0,tot=0;
ll c[maxn],block[maxn],n,m,size;
ll sq(ll x){return x*x;}
bool cmp1(const Q &a,const Q &b){
	if(block[a.l]!=block[b.l])return block[a.l]<block[b.l];
	else if(a.r!=b.r)return a.r<b.r;
	else return a.l<b.l;
}
bool cmp2(const Q &a,const Q &b){return a.id<b.id;}
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
void Update(ll p,ll add){
	ans1-=sq(cnt[p]);cnt[p]+=add;ans1+=sq(cnt[p]);
}
ll cal(ll len){return len*(len-1)/2;}
void Query(){
	++tot;
	for(ll i=q[tot-1].r;i>q[tot].r;i--)Update(c[i],-1);
	for(ll i=q[tot-1].r+1;i<=q[tot].r;i++)Update(c[i],1);
	for(ll i=q[tot-1].l;i<q[tot].l;i++)Update(c[i],-1);
	for(ll i=q[tot-1].l-1;i>=q[tot].l;i--)Update(c[i],1);
	ll len=q[tot].r-q[tot].l+1;ans2=cal(len);
	q[tot].ans1=(ans1-len)/2;q[tot].ans2=ans2;
}
int main(){
	scanf("%lld%lld",&n,&m);size=(ll)sqrt(n);
	ll bh=0;for(ll i=1;i<=n;i++){if((i-1)%size==0)bh++;block[i]=bh;}
	for(ll i=1;i<=n;i++)scanf("%lld",&c[i]);
	q[0].l=q[0].r=q[0].ans1=q[0].ans2=q[0].id=0;
	for(ll i=1;i<=m;i++)scanf("%lld%lld",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+m+1,cmp1);
	for(ll i=1;i<=m;i++)Query();
	sort(q+1,q+m+1,cmp2);
	for(ll i=1;i<=m;i++){
		ll g=gcd(q[i].ans1,q[i].ans2);
		q[i].ans1/=g,q[i].ans2/=g;
	} 
	for(ll i=1;i<=m;i++)printf("%lld/%lld\n",q[i].ans1,q[i].ans2);
	return 0;
}