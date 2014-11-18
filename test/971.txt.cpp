#include<stdio.h>
struct std
{
 int link,num,hash,s;
}date[10001],temp,x;
struct disjoint
{
  int enemy;
}set[10001];
int n,m;
int f[10001],e[10001];
char p[5001][5];
void quick1(int left,int right)
{
  int i,j;
  i=left;j=right;x=date[(left+right)/2];
  do{
    while(i<right&&date[i].num<x.num)i++;
    while(j>left&&date[j].num>x.num)j--;
    if(i<=j)
      {
        temp=date[i];
        date[i]=date[j];
        date[j]=temp;
        i++;j--;
       }                                    
    }while(i<=j);
  if(i<right)quick1(i,right);
  if(j>left)quick1(left,j);
}
void quick2(int left,int right)
{
  int i,j;
  i=left;j=right;x=date[(left+right)/2];
  do{
    while(i<right&&date[i].link<x.link)i++;
    while(j>left&&date[j].link>x.link)j--;
    if(i<=j)
      {
        temp=date[i];
        date[i]=date[j];
        date[j]=temp;
        i++;j--;
       }                                    
    }while(i<=j);
  if(i<right)quick2(i,right);
  if(j>left)quick2(left,j);
}
void init()
{
  int i,j;
  scanf("%d %d",&n,&m);
  for(i=1;i<=m;i++)
  {
    scanf("%d %d %s\n",&date[2*i-1].num,&date[2*i].num,p[i]);
    date[2*i-1].num--;
    date[2*i-1].link=2*i-1;date[2*i].link=2*i;
  }
  quick1(1,2*m);
  j=1;
  date[1].hash=j;
  for(i=2;i<=2*m;i++){
                      if(date[i].num!=date[i-1].num)j++;
                      date[i].hash=j;
                      }
  quick2(1,2*m);
}
void Union(int x,int y)
{
  if(x==0||y==0)return ;
  int i;
  for(i=1;i<=2*m;i++)
  if(date[i].s==x)date[i].s=y;
}
void work()
{
  int i,j;
  for(i=1;i<=2*m;i++){
                      set[i].enemy=0;
                       date[i].s=date[i].hash;
                      }
  for(i=1;i<=m;i++){
                    if(p[i][0]=='e')
                    {
                     if(date[2*i-1].s==set[date[2*i].s].enemy||date[2*i].s==set[date[2*i-1].s].enemy)
                     {
                       printf("%d",i-1);return ;
                     }
                     j=set[date[2*i-1].s].enemy;
                     Union(set[date[2*i-1].s].enemy,set[date[2*i].s].enemy);
                     Union(date[2*i-1].s,date[2*i].s);  
                     if(set[date[2*i].s].enemy==0)set[date[2*i].s].enemy=j;
                    } 
                    if(p[i][0]=='o')
                    {
                     if(date[2*i-1].s==date[2*i].s)
                     {
                      printf("%d",i-1);return ;                              
                     }            
                     Union(set[date[2*i-1].s].enemy,date[2*i].s);
                     Union(set[date[2*i].s].enemy,date[2*i-1].s);
                     set[date[2*i-1].s].enemy=date[2*i].s;
                     set[date[2*i].s].enemy=date[2*i-1].s;    
                    }
                   }
  printf("%d",m);  
}
int main()
{
   init();
    work();
    return 0;
}

