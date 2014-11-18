/*
Author: Tim
Date:
Description
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>

#define Inf (2147483647)
#define sqr(a) (a*a)
#define Fv(i,v) for (int i=0;i<v;i++)
#define Mkp(p,q) make_pair(p,q)

using namespace std;

struct BigInt{
	   int d[5000],l;
	   inline void operator =(int p){
	   		  l=1;
	   		  memset(d,0,sizeof(d));
	   		  d[0]=p;
		  	  }
	   inline void operator *=(int p){
	   		  for (int i=0;i<l;i++) d[i]*=p;
	   		  for (int i=0;i<l;i++) {d[i+1]+=d[i]/10;d[i]%=10;}
	   		  while (d[l]){d[l+1]+=d[l]/10;d[l]%=10;l++;}
	   }
	   inline void Out(){for (int i=l-1;i>=0;i--) printf("%d",d[i]);printf("\n");}
}P;

int a[5000];

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
	int N;
	scanf("%d",&N);
	P=1;
	int t=0,rec=2;
	while (N>=rec){
		  N-=rec;
		  a[t++]=rec;
		  rec++;
 	}
 	if (N>t) {N-=t;for (int i=0;i<t;i++) a[i]++;}
 	int j=t-1;
 	while (N--) {a[j]++;j--;}
 	for (int i=0;i<t-1;i++) {printf("%d ",a[i]);P*=a[i];}
 	printf("%d\n",a[t-1]);P*=a[t-1];
 	P.Out();
    return 0;
}


