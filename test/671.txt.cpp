#include<iostream>
using namespace std;
int n;
char a[3][1000001];
void init()
{
     int i;
     string s;
     cin>>s;
     n=s.size();
     for (i=0;i<n;i++)
      a[1][i+1]=s[i];
     cin>>s;
     for (i=0;i<n;i++)
      a[2][i+1]=s[i];
}
int find(int flag)
{
    int i=1,j=2,k=0,fi,fj;
    while (i<=n && j<=n && k<=n)
    {
          fi=(i+k);fj=(j+k);
          if ( fi>n ) fi=fi-n;
          if ( fj>n ) fj=fj-n;
          if ( a[flag][fi]==a[flag][fj] )
           k++;
          else
          {
              if ( a[flag][fi]>a[flag][fj] )
               i=i+k+1;
              else
               j=j+k+1;
              if ( j==i )j++;
              k=0;
          }
    }
    return(min(i,j));
}
void work()
{
     int s1,s2,i,f1,f2;
     s1=find(1);s2=find(2);
     for (i=0;i<n;i++)
     {
         f1=s1+i;f2=s2+i;
         if ( f1>n ) f1=f1-n;
         if ( f2>n ) f2=f2-n; 
         if ( a[1][f1]!=a[2][f2] )
         {
              cout<<"No";
              exit(0);
         }
     }
     cout<<"Yes"<<endl;
     for (i=0;i<n;i++)
     {
         f1=s1+i;
         if ( f1>n ) f1=f1-n;
         cout<<a[1][f1];
     }
}
main()
{
      init();
      work();
}
