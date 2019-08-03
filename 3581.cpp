#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=500005;
ll trie[maxn][27],sum[maxn],f[maxn];
char ch[maxn];
ll dp(ll x){
	ll ans=1;//printf("%lld ",x);
	for(ll i=0;i<26;i++)if(trie[x][i])ans*=dp(trie[x][i]);
	return ans+sum[x];
}
int main(){
	ll x=0,cnt=0;ll n;scanf("%lld",&n);
	for(ll k=1;k<=n;k++){
		scanf("%s",ch);x=0;
		ll len=strlen(ch);
		for(ll i=0;i<len;i++){
			ll y=ch[i]-'a';//printf("%lld ",y);
			if(!trie[x][y])trie[x][y]=++cnt;
			x=trie[x][y];
		}
		sum[x]=1;
	}
	printf("%lld",dp(0));
	return 0;
}