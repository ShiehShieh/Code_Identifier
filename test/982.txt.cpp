#include "stdio.h"
#include "string.h"
int main()
{ char a[10005],b[10005];
 int x[10005]={0},y[10005]={0},s[20015]={0},i,j,n,m,d=0,t=0,t1=0,len;
 scanf("%s%s",a,b);
 n=strlen(a);
 m=strlen(b);
 for(i=n-4;i>=0;i-=4)
      x[t++]=(a[i]-'0')*1000+(a[i+1]-'0')*100+(a[i+2]-'0')*10+(a[i+3]-'0')*1;
 if(n-t*4==3)
      x[t]=(a[0]-'0')*100+(a[1]-'0')*10+(a[2]-'0')*1;
 else
      if(n-t*4==2)
      x[t]=(a[0]-'0')*10+(a[1]-'0')*1;
 else
      if(n-t*4==1)
      x[t]=a[0]-'0';
 for(j=m-4;j>=0;j-=4)
      y[t1++]=(b[j]-'0')*1000+(b[j+1]-'0')*100+(b[j+2]-'0')*10+(b[j+3]-'0')*1;
 if(m-t*4==3)
      y[t1]=(b[0]-'0')*100+(b[1]-'0')*10+(b[2]-'0')*1;
 else
    if(m-t*4==2)
      y[t1]=(b[0]-'0')*10+(b[1]-'0')*1;
 else
    if(m-t*4==1)
      y[t1]=b[0]-'0';
 for(i=0;i<=t+1;i++)
 {   
      for(j=0;j<=t1+1;j++)
	  {   
          s[i+j]+=x[i]*y[j];
          s[i+j+1]+=s[i+j]/10000;
          s[i+j]=s[i+j]%10000;
	  }
 }
 len=m+n;
 while(s[len]==0)
      len--;
 t=t1=0;
 for(i=n-1;i>=0;i--,t++)
    if(a[i]!=0)
      break;
 for(i=m-1;i>=0;i--,t1++)
    if(b[i]!=0)
      break;
 for(i=len;i>=0;i--)
 {
      if(i==len)
          printf("%d",s[i]);
      else
          printf("%.4d",s[i]);
 } 
 return 0;
}
