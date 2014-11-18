#include<iostream>
using namespace std;
int n,a[1001],p[1001],c[1001];
void init()
{
     string s;
     int x,i,flag;
     do
     {
            s="";
            cin>>s>>x;
            flag=0;
            if ( s!="" )
            {
                 n++;
                 p[n]=x;
                 for (i=0;i<s.size();i++)
                 {
                     c[n]+=flag;
                     if ( s[i]!='.' )
                      a[n]=a[n]*10+s[i]-'0';
                     else
                      flag=1;
                 }
                 c[n]*=p[n];
            }
     }while (s!="");
}
void pow(int x)
{
     int s[5001],i,j,w;
     memset(s,0,sizeof(s));
     s[0]=s[1]=1;
     for (i=1;i<=p[x];i++)
     {
         for (j=1;j<=s[0];j++)
             s[j]*=a[x];
         for (j=1;j<s[0];j++)
         {
             s[j+1]+=(s[j]/10);
             s[j]%=10;
         }
         while ( s[s[0]]>9 )
         {
               s[s[0]+1]=(s[s[0]]/10);
               s[s[0]]%=10;
               s[0]++;
         }
     }
     w=1;
     while (s[w]==0)
     {
           w++;
           c[x]--;
     }
     for (i=s[0];i>=w+c[x];i--)
      cout<<s[i];
     if ( w+c[x]-1>=w )
     cout<<".";
     for (i=w+c[x]-1;i>=w;i--) 
      cout<<s[i];
     cout<<endl;
}
void work()
{
     int i;
     for (i=1;i<=n;i++)
         pow(i);
}
main()
{
      init();
      work();
}
