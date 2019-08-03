#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 500005
inline int lowbit(int x){return x&(-x);}
int c[maxn];
int a[maxn];
int n;
int sum(int i){
	int s=0;
	while(i){
		s+=c[i];
		i-=lowbit(i);
	}
	return s;
}
void updata(int i,int v){
	while(i<=n){
		c[i]+=v;
		i+=lowbit(i);
	}
	return;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","r",stdout);
	int k;
	int i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		int j,t=i-lowbit(i);
		for(j=t+1;j<=i;j++){
			c[i]+=a[j];
		}
	}
//	printf("%d\n",sum(3));
	int s=0;
	for(i=1;i<=n;i++){
		int j;
		for(j=i;j<=n;j++){
			int ss=sum(j)-sum(i-1);
			if(ss==k){
				s++;
			}else{
				if(ss>k){
					break;
				}
			}
		}
	}
	printf("%d",s);
	return 0;
}
