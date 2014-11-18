#include<iostream>
using namespace std;
const long a[66]= {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,
 47,53,59,61,67,71,73,79,83,89,97,101,103,
 107,109,113,127,131,137,139,149,151,157,
 163,167,173,179,181,191,193,197,199,211,
 223,227,229,233,239,241,251,257,263,269,
 271,277,281,283,293,307,311,313};
void mul(long a[1000],long n)
{ long i;
 for (i=1; i<=a[0]; i++) a[i]=a[i]*n;
 for (i=1; i<a[0]; i++) {a[i+1]+=a[i]/10; a[i]%=10;}
 while (a[a[0]]>9) {a[a[0]+1]=a[a[0]]/10; a[a[0]]%=10; a[0]++;}
 if (a[0]>101) a[0]=101;
}
main(){
 long j,n,m,all,h[200000],i,nn,mm,ans[1000];
 scanf("%d %d",&n,&m);
 all=n+m;
 memset(h,0,sizeof(h));
 for (i=n+1; i<=all; i++)
{ nn=i;
for (j=1; j<=65; j++)
{ while (nn%a[j]==0)
{h[a[j]]++; nn/=a[j]; if (nn==1) break;}
if (nn==1) break;}
if (nn!=1) h[nn]++;
}
 for (i=1; i<=m; i++)
{ mm=i;
for (j=1; j<=65; j++)
{ while (mm%a[j]==0)
{h[a[j]]--; mm/=a[j]; if (mm==1) break;}
if (mm==1) break;}
if (mm!=1) h[mm]--;
}
 ans[0]=1; ans[1]=1;
 for (i=1; i<=100000; i++)
while (h[i]>0)
{mul(ans,i); h[i]--;}
 for (i=100; i>=1; i--) {printf("%d",ans[i]); if (i%10==1) printf("\n");}
}
