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

ll a[105];
ll n;
ll vis[25005];

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

int main(){
//	freopen("money.in","r",stdin);
//	freopen("money.out","w",stdout);
	int t;scanf("%d",&t);
	
	while(t--){
		memset(a,0,sizeof a);
		memset(vis,0,sizeof vis);
		n=read();
		for(ll i=1;i<=n;i++)a[i]=read(),vis[a[i]]=-1;
		sort(a+1,a+n+1);
		for(ll i=1;i<=a[n];i++){
			for(ll j=1;j<=n;j++){
				if(a[j]<=i){
					if(vis[i-a[j]]){
						vis[i]=j;
						break;
					}
				}
			}
		}
		ll ans=0;
		for(ll i=1;i<=n;i++)if(vis[a[i]]==-1)ans++;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
2 4
3 19 10 6
5
11 29 13 19 17
*/