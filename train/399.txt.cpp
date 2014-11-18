/*Vijos P1500*/
#include<iostream>
#include<string>
using namespace std;
#define min(a,b) (a<b ? a:b)
string s,a[1000];
long b[26][26];
long n,i,j,x;
int bj(string x,string y)
{
     long l1=x.size(),l2=y.size(),i;
     for (i=0;i<min(l1,l2);i++)
     {
         if (b[x[i]-97][y[i]-97]==0) continue;
         return b[x[i]-97][y[i]-97];
     }
     if (l1<l2) return -1;
     if (l1>l2) return 1;
     return 0;
}
int comp(const void *a,const void *b)
{
     return bj(*(string*)a,*(string*)b);
}
int main()
{
    cin>>s;
    for (i=0;i<26;i++)
    {
        b[i][i]=0;
        for (j=i+1;j<26;j++)
        {
            b[s[i]-97][s[j]-97]=-1;
            b[s[j]-97][s[i]-97]=1;
        }
    }
    cin>>n;
    for (i=0;i<n;i++) cin>>a[i];
    qsort(a,n,sizeof(a[0]),comp);
    cin>>x;
    if (x==1) for (i=0;i<n;i++) cout<<a[i]<<endl;
       else for (i=n-1;i>=0;i--) cout<<a[i]<<endl;
    return 0;
}

