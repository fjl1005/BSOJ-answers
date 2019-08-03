#include<cstdio>

#define ll long long
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define fa(x) (x>>1)

inline double Max(double a,double b){return a>b?a:b;}
inline double Min(double a,double b){return a<b?a:b;}

const ll maxn = 10005;
const ll maxm = 40005;
const ll maxc = 1000005;
ll n=0;
double ans=0;
struct p{
	double x1,y1,x2,y2;
}g[maxn*4];
ll top=0;

void update(double x1,double y1,double x2,double y2){++top;g[top].x1=x1,g[top].y1=y1,g[top].x2=x2,g[top].y2=y2;}

void cut(ll v,double x1,double y1,double x2,double y2,ll cmd){
	if(cmd==0){
		double k1=Max(x1,g[v].x1);
		double k2=Min(x2,g[v].x2);
		if(g[v].x1<k1)update(g[v].x1,g[v].y1,k1,g[v].y2);
		if(g[v].x2>k2)update(k2,g[v].y1,g[v].x2,g[v].y2);
		cut(v,k1,y1,k2,y2,cmd+1);
	}
	if(cmd==1){
		double k1=Max(y1,g[v].y1);
		double k2=Min(y2,g[v].y2);
		if(g[v].y1<k1)update(x1,g[v].y1,x2,k1);
		if(g[v].y2>k2)update(x1,k2,x2,g[v].y2);
	}
}

int main(){
	ll t=1;
	while(scanf("%lld",&n)!=EOF){
		if(n==0)return 0;
		ans=0,top=0;
		for(ll i=1;i<=n;i++){
			double x1,y1,x2,y2;
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			for(ll j=0;j<=top;j++){
				if(g[j].x1>=x2||g[j].y1>=y2||g[j].x2<=x1||g[j].y2<=y1)continue;
				cut(j,x1,y1,x2,y2,0);
				g[j]=g[top];
				top--,j--;
			}
			update(x1,y1,x2,y2);
		}
		for(ll i=1;i<=top;i++)ans+=(g[i].x2-g[i].x1)*(g[i].y2-g[i].y1);
		printf("Test case #%lld\n",t);t++;
		printf("Total explored area: %.2lf\n\n",ans);
	
	}
	return 0;
}
/*
20 20 3
2 2 18 18 2
0 8 19 19 3
8 0 10 19 4

*/