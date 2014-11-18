#include<iostream>
#include<string.h>
using namespace std;
 char a[300];
 int map[5][10]={{2,1,2,2,1,2,2,2,2,2},
                {5,3,3,3,5,4,4,3,5,5},
                {1,1,2,2,2,2,2,1,2,2},
                {5,3,4,3,3,3,5,3,5,3},
                {2,1,2,2,1,2,2,1,2,2}};
/*1->' ' 2->'-' 3->' |' 4->'| ' 5->'||'*/
main()
{int ka,k,i,j,m;
  cin>>k>>a;
  ka=strlen(a);
  for(int z=0;z<5;z++)
     {if(z==0||z==2||z==4)
        {for(i=0;i<ka;i++)
            {if(i>0)cout<<' ';
             cout<<' ';
             if(map[z][a[i]-'0']==1)
               {for(j=1;j<=k;j++)cout<<' ';
               }
             else
               {for(j=1;j<=k;j++)cout<<'-';
               } 
             cout<<' ';
            } 
        cout<<endl;  
        }
     else
       {for(j=1;j<=k;j++)
           {for(i=0;i<ka;i++)
               {if(i>0)cout<<' ';
                if(map[z][a[i]-'0']==3)cout<<' ';
                else cout<<'|';
                for(m=1;m<=k;m++)cout<<' ';
                if(map[z][a[i]-'0']==4)cout<<' ';
                else cout<<'|';
                }
           cout<<endl;
           }
       }   
    } 
 }
