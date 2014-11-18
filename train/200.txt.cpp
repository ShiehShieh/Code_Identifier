#include<stdio.h>
#include<string.h>
#define SIZE 50010
int l[SIZE],r[SIZE];
int n,m;
inline int low_bit(int t)
{return t&(-t);}
void modify(int *tree,int pos,int x)
{
     while(pos<=n)
     {
            tree[pos]+=x;
            pos+=low_bit(pos);      
     }     
}
int sum(int *tree,int pos)
{
     int res=0;
     while(pos>0)
     {
         res+=tree[pos];
         pos-=low_bit(pos);            
     }    
     return res;
}
int main()
{
  
    scanf("%d%d",&n,&m);
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    int x,a,b;
    while(m--)
    {
              scanf("%d%d%d",&x,&a,&b);
              if(x==1)
              {
                   modify(l,a,1);      
                   modify(r,b,1);        
              }else
              {
                   printf("%d\n",sum(l,b)-sum(r,a-1));     
              }
    }
}
