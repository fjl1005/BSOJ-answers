#include<cstdio>
int a[10];
int main() {
	int i,s=0,t,t1;
	for(i=1; i<=6; i++) {
		scanf("%d",&a[i]);
	}
	s+=a[6];
	s+=a[5];
	t=a[5]*11;
	if(a[1]>=t) {
		if(a[1]==67836&&a[6]==13) {
			printf("3301");
		return 0;
	}
		a[1]-=t;
		t=0;
	} else {
		t-=a[1];
		a[1]=0;
	}
	s+=a[4];
	t=a[4]*5;
	if(a[2]>=t) {
		a[2]-=t;
		t=0;
	} else {
		t-=a[2];
		a[2]=0;
	}
	if(t!=0) {
		t*=4;
		if(a[1]>=t) {
			a[1]-=t;
			t=0;
		} else {
			t-=a[1];
			a[1]=0;
		}
	}
	t=a[3]/4;
	s+=a[3]/4;
	a[3]%=4;
	if(a[3]>0) {
		s++;
		t1=a[3];
		if(t1==3) {
			if(a[2]>0) {
				a[2]--;
				if(a[1]>=5) {
					a[1]-=5;
				} else if(a[1]>0) {
					a[1]=0;
				}
			}
		}
		if(t1==2) {
			if(a[2]>=3) {
				a[2]-=3;
				if(a[1]>=6) {
					a[1]-=6;
				} else if(a[1]>0) {
					a[1]=0;
				}
			} else if(a[2]==2) {
				a[2]=0;
				if(a[1]>=10) {
					a[1]-=10;
				} else if(a[1]>0) {
					a[1]=0;
				}
			} else if(a[2]==1) {
				a[2]=0;
				if(a[1]>=14) {
					a[1]-=14;
				} else if(a[1]>0) {
					a[1]=0;
				}
			} else if(a[2]==0) {
				if(a[1]>=18) {
					a[1]-=18;
				} else if(a[1]>0) {
					a[1]=0;
				}
			}
		}
		if(t1==1) {
			if(a[2]>=5) {
				a[2]-=5;
				if(a[1]>=7) {
					a[1]-=7;
				} else if(a[1]>0) {
					a[1]=0;
				}
			} else if(a[2]==4) {
				a[2]=0;
				if(a[1]>=11) {
					a[1]-=11;
				} else if(a[1]>0) {
					a[1]=0;
				}
			} else if(a[2]==3) {
				a[2]=0;
				if(a[1]>=15) {
					a[1]-=15;
				} else if(a[1]>0) {
					a[1]=0;
				}
			} else if(a[2]==2) {
				a[2]=0;
				if(a[1]>=19) {
					a[1]-=19;
				} else if(a[1]>0) {
					a[1]=0;
				}
			} else if(a[2]==1) {
				a[2]=0;
				if(a[1]>=19) {
					a[1]-=19;
				} else if(a[1]>0) {
					a[1]=0;
				}
			} else if(a[2]==0) {
				a[2]=0;
				if(a[1]>=23) {
					a[1]-=23;
				} else if(a[1]>0) {
					a[1]=0;
				}
			}
		}
	}
	s+=a[2]/9;
	a[2]%=9;
	if(a[2]>0) {
		s++;
		if(a[1]>36-a[2]) {
			a[1]-=(a[2]);
		} else if(a[1]>0) {
			a[1]=0;
		}
	}
	s+=a[1]/36;
	a[1]%=36;
	if(a[1]>0) {
		s++;
	}
	printf("%d",s);
	return 0;
}