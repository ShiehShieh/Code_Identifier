#include<iostream>
using namespace std;
int a[10];
int clean()
{int i;
 for(i=1;i<=9;i++)
   a[i]=0;
}
int main()
{int n,map[10][10],i,j,k,l,m,flag;
 cin>>n;
 for(i=1;i<=n;i++)
   {flag=1;
    for(j=1;j<=9;j++)
      for(k=1;k<=9;k++)
        cin>>map[j][k];
    clean();
    for(j=1;j<=9;j++)
      {for(k=1;k<=9;k++)
         {if(a[map[j][k]]==0)
            a[map[j][k]]=1;
          else
            flag=0;
         }
       clean();
      }
    for(j=1;j<=9;j++)
      {for(k=1;k<=9;k++)
         {if(a[map[k][j]]==0)
            a[map[k][j]]=1;
          else
            flag=0;
         }
       clean();
      }
    for(j=1;j<=7;j+=3)
      for(k=1;k<=7;k+=3)
        {for(l=j;l<=j+2;l++)
           for(m=k;m<=k+2;m++)
             {if(a[map[l][m]]==0)
                a[map[l][m]]=1;
              else
                flag=0;
             }
         clean();
        }
    if(flag==0)
      cout<<"Wrong"<<endl;
    else
      cout<<"Right"<<endl;
   }
 return 0;
}   
        

