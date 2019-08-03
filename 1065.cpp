#include<cstdio>
#define ll long long
#define maxm 20005
#define maxn 105

ll u[maxm],v[maxm],w[maxm];
ll first[maxn],next[maxm];
ll tot=0;

inline void addedge(ll a,ll b,ll c){
    tot++;
    u[tot]=a,v[tot]=b,w[tot]=c;
    next[tot]=first[a];
    first[a]=tot;
}

ll n,m;

ll c[maxn],U[maxn];

ll q[maxn],l[maxn];
ll head,tail;

ll in[maxn],pd[maxn];

int main(){
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld%lld",&c[i],&U[i]);
    }
    for(ll i=1;i<=m;i++){
        ll a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        in[b]++;
        addedge(a,b,c);
    }
    head=1,tail=0;
    for(ll i=1;i<=n;i++){
        if(!in[i])q[++tail]=i,pd[i]=1;
    }
    while(head<=tail){
        ll p=q[head];head++;
        if(!pd[p])c[p]-=U[p];
        for(ll i=first[p];i;i=next[i]){
            in[v[i]]--;
            if(!in[v[i]])q[++tail]=v[i],l[v[i]]=l[p]+1;
            if(c[p]>0)c[v[i]]+=c[p]*w[i];
        }
    }
    int op=0;
    for(ll i=1;i<=n;i++)if(l[i]>op)op=l[i];
    if(n!=1&&op==0)return printf("NULL")%1;
    int flag=1;
    for(ll i=1;i<=n;i++){
        if(l[i]==op&&c[i]>0){
            printf("%lld %lld\n",i,c[i]);
            flag=0;
        }
    }if(flag)printf("NULL");
    
    return 0;
}