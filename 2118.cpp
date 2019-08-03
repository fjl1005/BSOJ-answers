#include<cstdio>

#define inf 999999999999999999999999
#define random(a,b) (rand()*rand())%(b-a+1)+a
inline int Max(int a,int b) {return a>b?a:b;}
inline int Min(int a,int b) {return a<b?a:b;}
inline int Abs(int x) {return x<0?-x:x;}
inline void Swap(int &a,int &b) {a^=b^=a^=b;}

long long n,p,c;

long long map[1005][1005];
long long f[1005][1005];
long long np[1005];

void floyd(){
	for(int i=1;i<=p;i++){
		for(int j=1;j<=p;j++){
			f[i][j]=map[i][j];
		}
	}
	for(int k=1;k<=p;k++){
		for(int i=1;i<=p;i++){
			for(int j=1;j<=p;j++){
				if(f[i][k]+f[k][j]<f[i][j]){
					f[i][j]=f[i][k]+f[k][j];
				}
			}
		}
	}
}

void init(){
	for(int i=1;i<=p;i++){
		for(int j=1;j<=p;j++){
			map[i][j]=inf;
		}
		map[i][i]=0;
	}
}

int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld%lld%lld",&n,&p,&c);
	init();
	for(int i=1;i<=n;i++){
		scanf("%lld",&np[i]);
	}
	for(int i=1;i<=c;i++){
		long long x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		map[x][y]=map[y][x]=z;
	}
	floyd();
	long long Minn=inf;
	
//	int Mini;
	
	for(int i=1;i<=p;i++){
		long long sum=0;
		for(int j=1;j<=n;j++){
			sum+=f[i][np[j]];
		}
		if(sum<Minn){
			Minn=sum;
//			Mini=i;
		}
	}
	printf("%lld",Minn);
//	printf("\n%d",Mini);
	return 0;
}

