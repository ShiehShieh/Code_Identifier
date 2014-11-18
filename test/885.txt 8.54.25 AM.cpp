#include <iostream>
using namespace std;
int al(int x){
    int i=0,j,n;
    n=x;
    while(n!=0)
      {n/=10;
       i++;
      }
    for(j=0;j<4-i;j++)
      cout<<0;
    cout<<x;
return 0;
}
int main(){
    int i,j;
    string sa,sb;
    int a[10000]={0},b[10000]={0},c[10000]={0},x[2500]={0},l;
    int y[2500]={0},s,k,n=0,m=0;
    cin>>sa>>sb;
    for(i=0;i<sa.size();i++)
      a[i]=sa[i]-'0';
    for(i=0;i<sb.size();i++)
      b[i]=sb[i]-'0';
    k=sa.size();
    l=0;
    while(k>0)
      {s=0;
       if(k>4)
         for(j=k-4;j<k;j++)
           s=s*10+a[j];
       else 
         for(j=0;j<k;j++)
           s=s*10+a[j];
       x[l++]=s;
       k-=4;
      }
    n=l;
    k=sb.size();
    l=0;
    while(k>0)
      {s=0;
      if(k>4)
        for(j=k-4;j<k;j++)
          s=s*10+b[j];
      else
        for(j=0;j<k;j++)
          s=s*10+b[j];
      y[l++]=s;
      k-=4;
    }
    m=l;
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
        {c[i+j]+=x[i]*y[j];
         c[i+j+1]+=(c[i+j]/10000);
         c[i+j]%=10000;
        }
    for(i=m+n;i>=0;i--)
      if(c[i]) break;
    cout<<c[i];
    i-=1;
    for(;i>=0;i--)
      al(c[i]);
return 0;
}
