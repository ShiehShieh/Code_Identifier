#include <string>
#include <iostream>

using namespace std;
string a,b;
int Len1,Len2;
int ans[20002],tmp1[10000],tmp2[10000];

int pending(string a)
{
    int tmp=0;
    int i;
    for(i=0;i<a.size();i++)
      {
           tmp*=10;
           tmp+=(a[i]-'0');
      }
    return tmp;
}

int main(void)
{
    cin>>a>>b;
    Len1=a.length();
    Len2=b.length();
    
    int i,j,k;
    
    j=1;
    
    for(i=Len1-1;i>=0;i-=4)
       {
           if(i-3>=0)
               tmp1[j]=pending(a.substr(i-3,4));
           else
               tmp1[j]=pending(a.substr(0,i+1));
           j++;
       }
    
    Len1=j;
    j=1;
    
    for(i=Len2-1;i>=0;i-=4)
       {
           if(i-3>=0)
               tmp2[j]=pending(b.substr(i-3,4));
           else
               tmp2[j]=pending(b.substr(0,i+1));
           j++;
       }
    
    Len2=j;
    for(i=1;i<Len1;i++)
       for(j=1;j<Len2;j++)
           {
               ans[i+j-1]+=tmp1[i]*tmp2[j];
               ans[i+j]+=ans[i+j-1]/10000;
               ans[i+j-1]%=10000;
           }
    
    int digit=i+j+4;
    while(ans[digit]==0) --digit;
    
    cout<<ans[digit];
    for(k=digit-1;k>0;k--)
       printf("%04d",ans[k]);
    cout<<endl;
    return 0;
}

