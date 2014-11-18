#include<iostream>
#include<math.h>
#include<iomanip> 
using namespace std;
int n,m;
int x[10001],y[10001];
struct node
{
       int flag;
       node* next;
}a[10001];
double dis[10001],pi;
struct data
{
       int x;
}p[1000001];
int front,behind,in[10001];
void insert(int x,int w)
{
     node *p;
     p=&a[x];
     while (p->flag!=-1)
      p=p->next;
     p->flag=w;
     p->next=new(node);
     p->next->flag=-1;
}            
double suan(int a1,int a2)
{
       double x1,y1,x2,y2,s;
       x1=x[a1];y1=y[a1];x2=x[a2];y2=y[a2];
       s=6374*acos( cos(y1/180*pi)*cos(y2/180*pi)*cos(fabs(x2-x1)/180*pi)+sin(y1/180*pi)*sin(y2/180*pi)  );
       return(s);
}
void init()
{
     int i,j,p1,p2;
     char s1,s2;
     cin>>n;
     pi=3.14159265358;
     for (i=1;i<=n;i++)
     {
         dis[i]=100000000;
         a[i].flag=-1;
         cin>>x[i]>>s1>>y[i]>>s2;
         if ( s1=='W' )x[i]*=-1;
         if ( s2=='S' )y[i]*=-1;
     }
     do
     {
         p1=p2=-1;
         cin>>p1>>p2;
         if ( p1!=-1 && p2!=-1 )
              insert(p1,p2);
     }while (p1!=-1&&p2!=-1);
     
}
void spfa()
{
     int i;
     node *t;
     front=behind=1;
     p[1].x=1;in[1]=1;
     dis[1]=0;
     while ( front<=behind )
     {
           t=&a[p[front].x];
           while ( t->flag!=-1 )
           {
                 if ( dis[t->flag]>dis[p[front].x]+suan(p[front].x,t->flag) )
                 {
                      dis[t->flag]=dis[p[front].x]+suan(p[front].x,t->flag);
                      if ( in[t->flag]==0 )
                      {
                           behind++;
                           in[t->flag]=1;
                           p[behind].x=t->flag;
                      }
                 }
                 t=t->next;
           }
           in[ p[front].x ]=0;
           front++;
     }
     if ( dis[n]==100000000 )
     cout<<"Impossible";
     else
     cout<<fixed<<setprecision(2)<<dis[n];
}
main()
{
      init();
      spfa();
}

