#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define ll long long

inline ll read(){
	ll f=1,s=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+ch-'0';ch=getchar();}
	return f*s;
}

inline ll Min(ll a,ll b){
	return a<b?a:b;
}

struct point{
	ll d,id;
	bool operator <(const point &a)const{return d<a.d;}
}p[100005];

ll a[100005];
ll ans=0;

int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	ll n=read();
	for(ll i=1;i<=n;i++)a[i]=p[i].d=read(),p[i].id=i;
	sort(p+1,p+n+1);
	for(ll i=1;i<=n;i++){
		ans+=a[p[i].id];
		for(ll j=p[i].id-1;j>=1;j--){
			if(a[j]==0)break;
			a[j]-=a[p[i].id];
		}
		for(ll j=p[i].id+1;j<=n;j++){
			if(a[j]==0)break;
			a[j]-=a[p[i].id];
		}
		a[p[i].id]=0;
	}
	printf("%lld",ans);
	return 0;
}
/*
6
4 3 2 5 3 5
*/
