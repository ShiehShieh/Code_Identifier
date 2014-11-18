#include <cstdio>
#include <cstring>
#define MAX 100001
int h1[2*MAX],h2[2*MAX];
int a0[MAX],a1[MAX],a[MAX];
int line[MAX],n;
bool v1[MAX],v2[MAX];
int abs(int x)
{
	if(x>0) return x;
	else return 0-x;
}
int hash(int x)
{
	if(x>=0) return x;
	else return abs(x)+n;
}
int main()
{
	scanf("%d",&n);
	memset(a0,0,sizeof(a0));
	memset(a1,0,sizeof(a1));
	for(int i=1;i<=n;i++){
		scanf("%d",&line[i]);
		if(line[i]==0){
			a0[i]=a0[i-1]+1;
			a1[i]=a1[i-1];
		}
		else{
			a1[i]=a1[i-1]+1;
			a0[i]=a0[i-1];
		}
	}
	for(int i=1;i<=n;i++){
		a[i]=a0[i]-a1[i];
	}
	int p;
	for(int i=1;i<=n;i++){
		h2[hash(a[i])]=i;
	}
	for(int i=n;i>=1;i--){
		h1[hash(a[i])]=i;
	}
	int max=0;
	for(int i=1;i<=n;i++){
		int p;
		if(a[i]==0){
			p=i;
			if(p>max) max=p;
		}	
		int t=hash(a[i]);
		if(h2[t]-h1[t]>max) max=h2[t]-h1[t];
	}
	printf("%d\n",max);
	return 0;
}
