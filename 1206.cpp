#include<cstdio>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define fa(x) (x>>1)
#define ll long long

const ll unit=100001;
//1 full 0 empty -1 some

const ll maxn=100005,maxm=800005;

ll val[maxm],tag[maxm];

void pushup(ll v){
	if(val[lc(v)]==val[rc(v)])val[v]=val[lc(v)];
	else val[v]=-1;
}

void pushdown(ll v){
	if(tag[v]){
		val[lc(v)]=val[rc(v)]=tag[lc(v)]=tag[rc(v)]=tag[v];
		tag[v]=0;
	}
}

void update(ll v,ll l,ll r,ll ul,ll ur,ll cl){
	if(l>r)return;
	if(ul<=l&&r<=ur){val[v]=tag[v]=cl;return;}
	pushdown(v);
	ll mid=(l+r)>>1;
	if(ul<=mid)update(lc(v),l,mid,ul,ur,cl);
	if(ur>mid)update(rc(v),mid+1,r,ul,ur,cl);
	pushup(v);
}
ll st[maxm],top=0;
void query(ll v,ll l,ll r){
	if(l>r||!val[v])return;
	if(val[v]!=-1){st[++top]=val[v];return;}
	if(l==r)return;
	ll mid=(l+r)>>1;
	query(lc(v),l,mid);
	query(rc(v),mid+1,r);
}

ll n;
ll ans=0;

int main(){
	ll a=1,b=200000,xc;scanf("%lld%lld",&xc,&n);xc++;update(1,a,b,a,b,xc);
//	for(ll i=1;i<=100;i++)printf("%lld ",val[i]);
	for(ll i=1;i<=n;i++){ll l,r,c;scanf("%lld%lld%lld",&l,&r,&c);c++;if(l==r){i--,n--;continue;}l+=unit,r+=unit;r--;update(1,a,b,l,r,c);}
//	for(ll i=1;i<=100;i++)printf("%lld ",val[i]);
	query(1,a,b);
//	for(ll i=1;i<=top;i++)printf("%lld ",st[i]);puts("");
	for(ll i=1;i<=top;i++)if(st[i]!=st[i-1])ans++;
	printf("%lld",ans);
	return 0;
}

/*
1 10 5
1 9
9 10
1 5
5 10
1 3
*/