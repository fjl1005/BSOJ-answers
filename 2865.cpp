#include<cstdio>
int h[100005],n;
void swap(int x,int y) {
	int t;
	t=h[x];
	h[x]=h[y];
	h[y]=t;
	return;
}
void duidown(int i) {
	int t;
	bool flag=0;
	while(i*2<=n&&flag==0) {
		if(h[i]<h[i*2]) {
			t=i*2;
		} else {
			t=i;
		}
		if(i*2+1<=n) {
			if(h[t]<h[i*2+1]) {
				t=i*2+1;
			}
		}
		if(t!=i){
			swap(t,i);
			i=t;
		}else{
			flag=1;
		}
	}
	return;
}
void jiandui() {
	int mid=n/2,i;
	for(i=mid; i>0; i--) {
		duidown(i);
	}
	return;
}
void duipaixu() {
	while(n>1){
		swap(1,n);
		n--;
		duidown(1);
	}
	return;
}
int main() {
	int i,x;
	scanf("%d",&x);
	for(i=1;i<=x;i++){
		scanf("%d",&h[i]);
	}
	n=x;
	jiandui();
	duipaixu();
	for(i=1; i<=x; i++) {
		printf("%d ",h[i]);
	}
	return 0;
}