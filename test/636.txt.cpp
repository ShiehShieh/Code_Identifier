#include<iostream>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int match(int num)
{int s;
 if(num==0)
   return a[0];
 else
   {s=0;
    while(num>0)
      {s+=a[num%10];
       num/=10;
      }
    return s;
   } 
}
int main()
{int n,x,y,z,i,j,s;
 cin>>n;
 s=0;
 for(i=0;i<=1111;i++)
   {x=match(i);
    for(j=0;j<=1111;j++)
      {y=match(j);
       z=match(i+j);
       if(x+y+z+4==n)
         s++;
      }
   }
 cout<<s<<endl;
 cin>>i;
 return 0;
}

