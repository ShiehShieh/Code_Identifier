#include<stdio.h>
short date[10000001]={0};
int count(int num[],int k,int n)
{
  int i,j,s;
  j=1;
  s=0;
  for(i=n;i>=1;i--)
  {
    s+=num[i]*j;
    j*=k;
  }
  return s;   
}
int main()
{

  int a,b,length1,length2,n;
  scanf("%d %d %d %d %d",&length1,&length2,&a,&b,&n);
  int i,j,k,t,num[100],temp;
  for(i=length1;i<=length2;i++)
  {
   for(j=1;j<i;j++)
    for(k=0;k<i;k++)
    if(j!=k)
    {
      t=2;
      num[1]=j;num[2]=k;
      temp=count(num,i,t);
      while(temp<=b){
                    t++;
                    if(temp<a){
                              if(t%2)num[t]=j;
                              else num[t]=k;
                              temp=count(num,i,t);                    
                              continue;
                              }
                    date[temp]++; 
                    if(t%2)num[t]=j;
                    else num[t]=k;
                    temp=count(num,i,t);
                    } 
    }
  }
  for(i=a;i<=b;i++)
   if(date[i]==n&&i!=26)printf("%d\n",i); 
   return 0;
}
