#include<bits/stdc++.h>
using namespace std;
#define re register
#define ll int
const ll maxn = 800001;
ll n,m,cnt=0;
ll trie[maxn*50][2],sum[maxn*50],rt[maxn];
void Insert(ll &cur,ll pre,ll dep,ll num){
	cur=++cnt;sum[cur]=sum[pre]+1;
	trie[cur][0]=trie[pre][0],trie[cur][1]=trie[pre][1];
	if(dep==-1)return;re ll p=(num>>dep)&1;
	Insert(trie[cur][p],trie[pre][p],dep-1,num);
}
ll Query(ll x,ll y,ll dep,ll num){
	if(dep==-1)return 0;
	re ll p=((num>>dep)&1)^1,ans=sum[trie[y][p]]-sum[trie[x][p]];
	if(ans) return (1<<dep)+Query(trie[x][p],trie[y][p],dep-1,num);
	else return Query(trie[x][p^1],trie[y][p^1],dep-1,num);
}
ll s[maxn];
int main(){
	scanf("%d%d",&n,&m);
	Insert(rt[1],rt[0],25,0);
	for(re ll i=1;i<=n;i++){
		re ll t;scanf("%d",&t);
		s[i+1]=s[i]^t;
		Insert(rt[i+1],rt[i],25,s[i+1]);
	}
	n++;
	for(re ll i=1;i<=m;i++){
		char ch=getchar();while(ch!='A'&&ch!='Q')ch=getchar();
		if(ch=='A'){
			re ll x;scanf("%d",&x);s[n+1]=s[n]^x;Insert(rt[n+1],rt[n],25,s[n+1]);n++;
		}else{
			re ll l,r,x;scanf("%d%d%d",&l,&r,&x);x^=s[n];printf("%d\n",Query(rt[l-1],rt[r],25,x));
		}
	}
	return 0;
}