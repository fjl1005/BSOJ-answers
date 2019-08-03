#include<cstdio>
#include<cstring>
#include<stack>
using std::stack;
stack<char>pipei;
char a[300];
bool cheak(char t) {
	if(t=='<'||t=='{'||t=='('||t=='[') {
		return 1;
	}
	return 0;
}
bool test(char x,char y) {
	if(x=='<'&&y=='>') {
		return 1;
	}
	if(x=='{'&&y=='}') {
		return 1;
	}
	if(x=='['&&y==']') {
		return 1;
	}
	if(x=='('&&y==')') {
		return 1;
	}
	return 0;
}
bool dx(char x,char y) {
	if(x=='{') {
		return 1;
	}
	if(x=='[') {
		if(y=='{') {
			return 0;
		}
		return 1;
	}
	if(x=='(') {
		if(y=='{'||y=='[') {
			return 0;
		}
		return 1;
	}
	if(x=='<') {
		if(y!='<') {
			return 0;
		}
		return 1;
	}
	return 1;
}
void empty() {
	while(!pipei.empty()) {
		pipei.pop();
	}
	return;
}
int main() {
	int t,k;
	scanf("%d\n",&t);
	for(k=1; k<=t; k++) {
		gets(a+1);
		empty();
		int n=strlen(a+1),i;
		for(i=1; i<=n; i++) {
			if(cheak(a[i])) {
				if(pipei.empty()) {
					pipei.push(a[i]);
				} else {
					if(dx(pipei.top(),a[i])) {
						pipei.push(a[i]);
					} else {
						printf("NO\n");
						goto end;
					}
				}
			} else {
				if(pipei.empty()) {
					printf("NO\n");
					goto end;
				}
				if(!test(pipei.top(),a[i])) {
					printf("NO\n");
					goto end;
				} else {
					pipei.pop();
				}
			}
		}
		if(!pipei.empty()) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
end:
		;
	}
	return 0;
}

/*
5
{[(<>)]}
[()]
<>()[]{}
[{}]
{()}
*/
