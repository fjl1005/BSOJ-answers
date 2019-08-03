#include<cstdio>
#include<cstring>

char t[305][305],T[305][305];

char mi[1005],key[1005];

char answer[1005];
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	for(i='A'; i<='Z'; i++) {
		T['A'][i]=i;
	}
	for(i='B'; i<='Z'; i++) {
		for(j='A'; j<='Z'; j++) {
			T[i][j]=T[i-1][j]+1;
			if(T[i][j]>'Z') {
				T[i][j]=T[i][j]-'Z'+'A'-1;
			}
		}
	}
	int cc='a'-'A';
	for(i='a'; i<='z'; i++) {
		for(j='a'; j<='z'; j++) {
			t[i][j]=T[i-cc][j-cc]+cc;
		}
	}
	gets(key+1);
	gets(mi+1);
	int lk=strlen(key+1);
	int lm=strlen(mi+1);
	for(i=1; i<=lk; i++) {
		if(key[i]>='A'&&key[i]<='Z') {
			key[i]+=cc;
		}
	}
	for(i=lk+1; i<=lm; i++) {
		key[i]=key[i-lk];
	}

	for(i=1; i<=lm; i++) {
		bool flag=0;
		if(mi[i]>='A'&&mi[i]<='Z') {
			flag=1;
			mi[i]+=cc;
		}
		for(j='a'; j<='z'; j++) {
			if(t[key[i]][j]==mi[i]) {
				break;
			}
		}
		if(!flag) {
			answer[i]=j;
		}else{
			answer[i]=j-cc;
		}
	}
	puts(answer+1);
	return 0;
}
