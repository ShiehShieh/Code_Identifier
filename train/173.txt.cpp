#include<stdio.h>
int n,m,v,k,maxex;
struct std
{
 int a,b,t;
}date[20],temp,on[20];
void init()
{
     int i,j;
     scanf("%d %d %d",&n,&m,&v);
     for(i=1;i<=m;i++)
     scanf("%d %d %d",&date[i].a,&date[i].b,&date[i].t);
     for(i=1;i<m;i++)
      for(j=i+1;j<=m;j++)
      {
      if(date[j].a<date[i].a)
      {
       temp=date[j];
       date[j]=date[i];
       date[i]=temp;
      }
      }
}
void dfs(int num,int sum,int peo)
{
 int p,q;
 if(num==m+1){
              if(sum>maxex)maxex=sum;
              return ;
              }
 q=0;
 for(p=1;p<=k;p++)
 if(on[p].b<=date[num].a)q+=on[p].t;
 
 dfs(num+1,sum,peo); 
 
 if(peo-q+date[num].t<=v)
 {
 k++;
 on[k]=date[num];
 dfs(num+1,sum+date[num].t*(date[num].b-date[num].a),peo+date[num].t);
 k--;
 } 

}
int main()
{
    init();
    k=maxex=0;
    dfs(1,0,0);
    printf("%d",maxex);
    return 0;
}

