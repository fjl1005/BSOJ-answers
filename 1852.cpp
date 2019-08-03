#include<bits/stdc++.h>
using namespace std;
const int maxn=5000005;
int f[maxn],ans=0;
int v[maxn];char w[maxn];int first[maxn],next[maxn],tot=0;
void addedge(int a,int b,char c){
	tot++;v[tot]=b,w[tot]=c;
	next[tot]=first[a];first[a]=tot;
}
int main(){
	int x=0,cnt=0,p=0;char ch;
	int n;scanf("%d",&n);
	for(int k=1;k<=n;k++){
		ch=getchar();while(ch=='\n')ch=getchar();x=0;
		for(int i=0;ch!='\n';i++,ch=getchar()){
			int y;if('A'<=ch&&ch<='Z')y=ch-'A';
			if('a'<=ch&&ch<='z')y=ch-'a'+26;
			if(ch==' ')y=52;p=0;
			for(int j=first[x];j;j=next[j])
				if(w[j]==y){p=v[j];break;}
			if(!p)p=++cnt,addedge(x,p,y);
			x=p;f[x]++;ans=max((int)ans,(int)(i+1)*(int)f[x]); 
		}
	}
	printf("%d",ans);
	return 0;
}