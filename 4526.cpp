#include<cstdio>
#include<cstring>
#include<iostream>
#define FOR(a,b,c) for(int a=(b);a<=(c);a++)
using namespace std;
const int maxn = 400000+10;
const int INF=1e9;
struct Node{
		int mx,mr;
    	Node() { mx=-INF; }
	};
struct Segment_Tree {
	int n;
	int t[maxn],maxv[maxn],maxr[maxn];
	void build(int u,int L,int R) {
		int lc=u*2,rc=u*2+1;
		if(L==R) {
			maxv[u]=t[L];
			maxr[u]=L;
		}
		else {
			int M=L+(R-L)/2;
			build(lc,L,M);
			build(rc,M+1,R);
			if(maxv[lc]>maxv[rc]) {
				maxv[u]=maxv[lc];
				maxr[u]=maxr[lc];
			}
			else {
				maxv[u]=maxv[rc];
				maxr[u]=maxr[rc];
			}
		}
	}
	void init(int n,int*a) {
		this->n=n;
		FOR(i,1,n) t[i]=a[i];
		build(1,1,n);
	}
	int y1,y2;
	Node query(int u,int L,int R) {
	int lc=u*2,rc=u*2+1;
	if(y1<=L && R<=y2) {
		Node ans; 
		ans.mr=maxr[u],ans.mx=maxv[u];
		return ans;
	}
	else {
		int M=L+(R-L)/2;
		Node ans,tmp;
		if(y1<=M) {
                 tmp=query(lc,L,M);
                  if(tmp.mx>ans.mx) ans=tmp;
              }
              if(M<y2) {
                  tmp=query(rc,M+1,R);
                  if(tmp.mx>ans.mx) ans=tmp;
              }
              return ans;
          }
      }
      int x;
      void Add(int u,int L,int R) {
          int lc=u*2,rc=u*2+1;
          if(L==R) {
              maxv[u] = 0;
             maxr[u] = L;
        }
          else {
              int M=L+(R-L)/2;
              if(x<=M) Add(lc,L,M);
              else Add(rc,M+1,R);
              if(maxv[lc]>maxv[rc]) {
                  maxv[u]=maxv[lc];
                  maxr[u]=maxr[lc];
             }
              else {
                  maxv[u]=maxv[rc];
                  maxr[u]=maxr[rc];
              }
          }
      }
  }A,B;
  
  int s[maxn],sa[maxn],sb[maxn];
  int n;
  int read() {
      char c=getchar();
     while(!isdigit(c)) c=getchar();
      int x=0;
     while(isdigit(c)) {
          x=x*10+c-'0';
          c=getchar();
      }
      return x;
 }
 int main() {
     n=read();
     FOR(i,1,n) s[i]=read();
     FOR(i,1,n) sb[i]=read();
     FOR(i,1,n) sa[i]=2*s[i]+sb[i];
     
     A.init(n,sa),B.init(n,sb);
     
     int srank=0,ans=0;
     FOR(i,1,n) {
         int a,b;
         if(srank==0) a=0,b=1;
         else a=srank-1,b=srank+1;
        Node t1,t2;
         if(a) {
             B.y1=1,B.y2=a;
             t1=B.query(1,1,n);
         }
         if(b<=n) {
             A.y1=b,A.y2=n;
             t2=A.query(1,1,n);
             t2.mx=sb[t2.mr]+2*(s[t2.mr]-s[srank]);
         }
         int ansl=0,ansr=0;
         if(t1.mx!=-INF)  ansl=sb[t1.mr];
         if(t2.mx!=-INF)  ansr=t2.mx;
         Node res;
         if(ansl>ansr) res=t1; else res=t2,srank=res.mr;
        ans+= res.mx;
         printf("%d\n",ans);
         A.x=B.x=res.mr;
         A.Add(1,1,n),B.Add(1,1,n);
     }
     return 0;
 } 
