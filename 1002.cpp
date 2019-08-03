#include<cstdio>
#include<algorithm>
using namespace std;

#define ll long long
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define fa(x) (x>>1)

inline ll Max(ll a,ll b){return a>b?a:b;}

const ll maxn = 500005;

struct p{
	ll l,r;
	bool operator < (const p &a) const{return l<a.l;}
}a[maxn];

ll n;
ll d[maxn];
ll len=0;

ll found(ll x){
	return upper_bound(d+1,d+len+1,x)-d;
}

int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld%lld",&a[i].l,&a[i].r);
	sort(a+1,a+n+1);
	d[++len]=a[1].r;
	for(ll i=2;i<=n;i++){
		if(a[i].r>=d[len])d[++len]=a[i].r;
		else{
			ll j=found(a[i].r);
			d[j]=a[i].r;
		}
	}
	printf("%lld",len);
	return 0;
}

