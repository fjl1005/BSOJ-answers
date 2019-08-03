#include<cstdio>
#define ll long long
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define fa(x) (x>>1)

inline ll Max(ll a,ll b){return a>b?a:b;}

const ll maxn = 1005;

ll n;
ll a[maxn],d[maxn];
ll len=0;

ll found(ll x){
	ll l=1,r=len;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(l==r)return l;
		if(x<d[mid])r=mid-1;
		if(x>=d[mid])l=mid+1;
	}
	return l;
}

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	d[++len]=a[1];//printf("%lld\n",found(15));
	for(ll i=2;i<=n;i++){
		if(a[i]>=d[len])d[++len]=a[i];
		else{
			ll j=found(a[i]);
			d[j]=a[i];
		}
	}
	printf("%lld",len);
	return 0;
}

