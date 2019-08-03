#include <cstdio>
#include <cstring>
int a[305][305],f[305];
int maxarray(int n) {
    int Max=f[0],temp=0,i;
    for (i=0;i<n;i++) {
        if(temp>0){
			temp+=f[i];
        }else{
			temp=f[i];
        }
        if(temp>Max){
        	Max=temp;
		}
    }
    return Max;
}
int main() {
//	freopen("maxarray.in","r",stdin);
//	freopen("maxarray.out","w",stdout);
	int i,j,k,n,s=a[0][0],temp;
    scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++){
		memset(f,0,sizeof(f));
		for(j=i;j<n;j++) {
			for(k=0;k<n;k++) {
				f[k]+=a[j][k];
			}
			temp=maxarray(n);
			if(temp>s){
				s=temp;
			}
		}
	}
	printf("%d",s);
    return 0;
}