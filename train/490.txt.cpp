#include<iostream>
#include<cstring>
using namespace std;
void num1(int s[],string st1);
int a[2501],b[2501],c[5002];
int main()
{
    string str1,str2;
    
    int len;
    cin>>str1>>str2;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    num1(a,str1);    
    num1(b,str2);
    for(int i=1;i<=a[0];i++)
    for(int j=1;j<=b[0];j++)
     { 
    c[i+j-1]+=a[i]*b[j]; 
    c[i+j]+=c[i+j-1]/10000; 
    c[i+j-1]%=10000;     
    }
    len=a[0]+b[0]+1;
    while((c[len]==0)&&len>1)len--;
    cout<<c[len];
    for(int i=len-1;i>=1;i--)
    {
    if(c[i]<1000) cout<<'0';
    if(c[i]<100) cout<<'0';
    if(c[i]<10) cout<<'0';
    cout<<c[i];
    
 }
 cout<<endl;
    return 0;
}    
    void num1(int s[],string st1)
    {int k=1,count=1;
    s[0]=st1.length();
    for(int i=s[0]-1;i>=0;i--)
      { if (count%4==0) {s[k]+=(st1[i]-'0')*1000; if(i!=0) k++;}
      if (count%4==1) s[k]=(st1[i]-'0');
      if (count%4==2) s[k]+=(st1[i]-'0')*10;
      if (count%4==3) s[k]+=(st1[i]-'0')*100;
      count++;
     }
     s[0]=k;
     return;
     }
