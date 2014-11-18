#include<stdio.h>
#define CLEAR 0333333333
const int opr[10]={0,011011,0111,0110110,01001001,010111010,0100100100,011011000,0111000000,0110110000}; 
char done[0400000000];
int a[1000000],b[1000000]; 

int main()
{
  //freopen("__in.txt","r",stdin);freopen("__out.txt","w",stdout);//////////////
  int ii,i,t,now=0,sn=1,*s=a,*temp,*ts=b,n; 
  for(i=0;i<9;i++) {scanf("%d",&t);now|=(t<<(3*i));}
  s[0]=now;done[now]=10; 

loop:
  n=0; 
  for(ii=0;ii<sn;ii++) 
  { 
    now=s[ii]; 
    for(i=1;i<=9;i++)
    {
      t=(now+opr[i])&0333333333;
      if (done[t]) continue;
      done[t]=i; 
      if (t) {ts[n]=t;n++;}
      else goto answer; 
    }
  }
  temp=ts;ts=s;s=temp; 
  sn=n;
goto loop;
 
answer:
  sn=0; 
  while(done[t]<10)
  {
    sn++; 
    s[sn]=done[t];
    t=((t|0444444444)-opr[done[t]])&0333333333;
  }
  while(sn) {printf("%d ",s[sn]);sn--;} 
  putchar('\n'); 
  return 0; 
} 

