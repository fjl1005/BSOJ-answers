#include<cstdio>
int a[100005];
void fz(int l,int r,int &Max,int &Min){
	if(l==r){
		Max=Min=a[l];
		return;
	}
	if(l==r-1){
		if(a[l]>a[r]){
			Max=a[l];
			Min=a[r];
			return;
		}else{
			Max=a[r];
			Min=a[l];
			return;
		}
	}
	int Max1,Min1,Max2,Min2;
	fz(l,(l+r)/2,Max1,Min1);
	fz((l+r)/2+1,r,Max2,Min2);
	if(Max1>Max2){
		Max=Max1;
	}else{
		Max=Max2;
	}
	if(Min1<Min2){
		Min=Min1;
	}else{
		Min=Min2;
	}
	return;
}
int main(){
	int n,i,Max,Min;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	fz(0,n-1,Max,Min);
	printf("%d %d",Max,Min);
	return 0;
}