#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=100005;
ll trie[maxn][27];
char ch[maxn];
int main(){
	ll x=0,cnt=0;
	while(scanf("%s",ch)!=EOF){
		x=0;
		ll len=strlen(ch);
		for(ll i=0;i<len;i++){
			ll y=ch[i]-'A';
			if(!trie[x][y])trie[x][y]=++cnt;
			x=trie[x][y];
		}
	}
	printf("%lld",cnt+1);
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