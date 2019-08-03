#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 2000001;
ll trie[maxn][2];
ll n,st[maxn],top,ans,cnt=0;
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		ll t;scanf("%lld",&t);
		ll cur=0,la=0;top=0;
		for(ll j=31;j>=0;j--){
			ll to=((t>>j)&1)^1;
			if(!trie[cur][to])to^=1;
			la<<=1;la+=to;cur=trie[cur][to];
		}
		cur=0;
		for(ll j=31;j>=0;j--){
			ll to=(t>>j)&1;
			if(!trie[cur][to])trie[cur][to]=++cnt;
			cur=trie[cur][to];
		}
		ans=max(ans,t^la);
	}
	printf("%lld",ans);
	return 0;
}
