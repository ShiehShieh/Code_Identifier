#include<iostream>
using namespace std;
int n,m,p,people[5001];
int Find(int x)
{
     return people[x]==x?x:Find(people[x]); 
}
   
int main()
{
     cin>>n>>m>>p;
     for(int i=1;i<=n;i++)people[i]=i;
     int a,b;
     for(int i=0;i<m;i++)
     {
          cin>>a>>b;
          people[Find(a)]=Find(b);
     }
     for(int i=0;i<p;i++)
     {
          cin>>a>>b;
          if(Find(a)==Find(b))cout<<"Yes"<<endl;
          else cout<<"No"<<endl;      
     }      
//end
     return 0;
}
