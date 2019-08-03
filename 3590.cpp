#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=500005;
ll trie[maxn][27],sum[maxn];
char ch[maxn],p[maxn][15];
int main(){
	ll x=0,cnt=0;ll n;scanf("%lld",&n);
	for(ll k=1;;k++){
		char lk=getchar();if(lk=='\n')break;
		p[k][0]=lk;scanf("%s%s",p[k]+1,ch);x=0;getchar();
		ll len=strlen(ch);
		for(ll i=0;i<len;i++){
			ll y=ch[i]-'A';
			if(!trie[x][y])trie[x][y]=++cnt;
			x=trie[x][y];
		}
		sum[x]=k;
	}
	while(scanf("%s",ch)!=EOF){
		x=0;
		ll len=strlen(ch);
		for(ll i=0;i<len;i++){
			ll y=ch[i]-'A';
			if(!trie[x][y])trie[x][y]=++cnt;
			x=trie[x][y];
		}
		if(sum[x]==0)puts("eh");
		else printf("%s\n",p[sum[x]]);
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