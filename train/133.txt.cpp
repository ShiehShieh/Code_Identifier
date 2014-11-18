#include <iostream>
using namespace std;
int maxb(int b[])
{
    int max=0; 
    for (int i=0;i<26;i++)
        if (b[i]>max)
           max=b[i];
    return max; 
}
int minb(int b[])
{
    int min=100; 
    for (int i=0;i<26;i++)
        if (b[i]<min && b[i]!=0)
           min=b[i];
    return min; 
}
bool prime(int a)
{
     if (a==0 || a==1)
        return false;
     if (a==2)
        return true;     
     for (int i=2;i<=a/2;i++)
     {
         if (a%i==0)
            return 0; 
     } 
     return 1; 
} 
main()
{
      char a[100],m=97;
      int b[26],i;
      memset(a,0,sizeof(a)); 
      memset(b,0,sizeof(b)); 
      cin>>a;
      for (i=0;a[i]!=0;i++)
          b[int(a[i])-97]++;
      if (prime(maxb(b)-minb(b))) 
         cout<<"Lucky Word"<<endl<<maxb(b)-minb(b)<<endl;
      else
          cout<<"No Answer"<<endl<<0<<endl; 
      return 0; 
} 

