/*
ID: laiyao11
PROG: gift1
LANG: C++
*/
#include<iostream>
using namespace std;
int main()
{string name[11],t,r,last;
 int i,np,num,money,j,d[11]={0},give;
 cin>>np;
 for(i=1;i<=np;i++)
   cin>>name[i];
 while(1)
   {cin>>t;
    if(t!=last)
      {cin>>money>>num;
       if(num!=0)
         {give=money/num*num;
          for(i=1;i<=np;i++)
            if(t==name[i])
              {d[i]-=give;
               break;
              }
          for(i=1;i<=num;i++)
            {cin>>r;
             for(j=1;j<=np;j++)
               if(r==name[j])
                 {d[j]+=give/num;
                  break;
                 }
            }
         }
       last=t;
      }
    else
      break;
   }
 for(i=1;i<=np;i++)
   cout<<name[i]<<" "<<d[i]<<endl;
 return 0;
}
      
    
   

