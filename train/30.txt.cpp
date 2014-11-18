#include<iostream>
#include<cstring>
using namespace std;
main()
{char s,q[1002][300];
 int i;
 int a[300]={0};
 for(i=1;i<=26;i++)
    {cin>>s;
     a[int(s)]=i;
    }
 int n,x;
 cin>>n;
 for(i=1;i<=n;i++)
     {cin>>q[i];}
 cin>>x;
 bool z=1;
 while(z)
      {z=0;
       for(i=1;i<n;i++)
          {int ka,kb;
           ka=strlen(q[i]);
           kb=strlen(q[i+1]);
           for(int j=0;j<strlen(q[i]);j++)
              {if(j>kb)break;
               if(a[int(q[i][j])]>a[int(q[i+1][j])])
                 {char t[300];
                  strcpy(t,q[i+1]);
                  strcpy(q[i+1],q[i]);
                  strcpy(q[i],t);
                  z=1;
                  break;
                 }
              else if(a[int(q[i][j])]<a[int(q[i+1][j])])break;
              }
           }
       }
 if(x==1)
 {for(i=1;i<=n;i++)cout<<q[i]<<endl;}
 else
    for(i=n;i>=1;i--)cout<<q[i]<<endl; 
}
