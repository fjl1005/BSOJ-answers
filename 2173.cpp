#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1000005;
ll trie[maxn][27],sum[maxn];
char ch[maxn];
int main(){
	ll x=0,cnt=0;ll n;scanf("%lld",&n);
	for(ll k=1;k<=n;k++){
		scanf("%s",ch);x=0;ll l;scanf("%lld",&l);
		ll len=strlen(ch);
		for(ll i=0;i<len;i++){
			ll y=ch[i]-'A';
			if(!trie[x][y])trie[x][y]=++cnt;
			x=trie[x][y];
		}
		sum[x]=l;
	}ll m;scanf("%lld",&m);
	for(ll i=1;i<=m;i++){
		scanf("%s",ch);x=0;
		ll len=strlen(ch);
		for(ll i=0;i<len;i++){
			ll y=ch[i]-'A';
			if(!trie[x][y])trie[x][y]=++cnt;
			x=trie[x][y];
		}
		printf("%lld\n",sum[x]);
	}
	return 0;
}
/*
A
AN
ASP
AS
ASC
ASCII
BAS
BASIC
*/