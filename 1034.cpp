#include<cstdio>
#include<algorithm>
struct f{
	int x;
	int y;
}a1[1005];
int main(){
	int n,i,j,k,a,b,c,s,t=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&a1[i].x,&a1[i].y);
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			s=0;
			a=a1[j].y-a1[i].y;
			b=a1[i].x-a1[j].x;
			c=a1[i].x*a1[j].y-a1[j].x*a1[i].y;
			for(k=0;k<n;k++){
				if(a*a1[k].x+b*a1[k].y==c){
					s++;
				}
			}
			t=t>s?t:s;
		}
	}
	printf("%d",t);
	return 0;
}