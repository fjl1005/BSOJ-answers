#include<cstdio>
int a[1005][1005];
int main(){
    int n,i,j;
    scanf("%d",&n);
    a[1][1]=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            a[i][j]+=(a[i-1][j]+a[i][j-1])%100003;
        }
    }
    printf("%d",a[n][n]);
    return 0;
}