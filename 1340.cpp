#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 1200002;
ll trie[maxn*10][2];
ll n,a[maxn],ans,cnt=0;
ll l[maxn],r[maxn];
int main(){
	scanf("%lld",&n);
	ll t=0;
	for(ll i=1;i<=n;i++){scanf("%lld",&a[i]);a[i]^=a[i-1];}
	memset(trie,0,sizeof trie);
	for(ll i=1;i<=n;i++){
		t=a[i];
		ll cur=0,la=0;
		for(ll j=31;j>=0;j--){
			ll to=((t>>j)&1)^1;
			if(!trie[cur][to])to^=1;
			if(!trie[cur][to]){la=0;break;}
			la<<=1;la+=to;cur=trie[cur][to];
		}
		cur=0;
		for(ll j=31;j>=0;j--){
			ll to=(t>>j)&1;
			if(!trie[cur][to])trie[cur][to]=++cnt;
			cur=trie[cur][to];
		}
		l[i]=max(l[i-1],t^la);
	}
	memset(trie,0,sizeof trie);
	for(ll i=n;i>=1;i--){
		t=a[i];
		ll cur=0,la=0;
		for(ll j=31;j>=0;j--){
			ll to=((t>>j)&1)^1;
			if(!trie[cur][to])to^=1;
			if(!trie[cur][to]){la=0;break;}
			la<<=1;la+=to;cur=trie[cur][to];
		}
		cur=0;
		for(ll j=31;j>=0;j--){
			ll to=(t>>j)&1;
			if(!trie[cur][to])trie[cur][to]=++cnt;
			cur=trie[cur][to];
		}
		r[i]=max(r[i+1],t^la);
	}
//	for(ll i=1;i<=n;i++)printf("%lld ",l[i]);puts("");
//	for(ll i=1;i<=n;i++)printf("%lld ",r[i]);puts("");
	
	for(ll i=1;i<n;i++)ans=max(ans,l[i]+r[i+1]);
	printf("%lld",ans);
	return 0;
}