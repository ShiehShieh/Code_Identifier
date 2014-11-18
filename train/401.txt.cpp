#include<iostream>
using namespace std;
int main()
{
  int date[10],a,b,c,d,e,f,g,h,i,j,k,t;
  int temp[10],ans[10];
  for(i=1;i<=9;i++)cin>>date[i];
  k=40;
  for(a=0;a<4;a++)
   for(b=0;b<4;b++)
     for(c=0;c<4;c++)
      for(d=0;d<4;d++)
       for(e=0;e<4;e++)
         for(f=0;f<4;f++)
          for(g=0;g<4;g++)
           for(h=0;h<4;h++)
            for(i=0;i<4;i++)
            {
              temp[1]=(date[1]+a+b+d)%4;
              temp[2]=(date[2]+a+b+c+e)%4;
              temp[3]=(date[3]+b+c+f)%4;
              temp[4]=(date[4]+a+d+e+g)%4;
              temp[5]=(date[5]+a+c+e+g+i)%4;
              temp[6]=(date[6]+c+e+f+i)%4;
              temp[7]=(date[7]+d+g+h)%4;
              temp[8]=(date[8]+e+g+h+i)%4;
              temp[9]=(date[9]+f+h+i)%4;
              t=1;
              for(j=1;j<=9;j++)if(temp[j]>0){t=0;break;}
              if(t==0)continue;
               if(a+b+c+d+e+f+g+h+i<=k)
                 {
                   k=a+b+c+d+e+f+g+h+i;
                   ans[1]=a;ans[2]=b;ans[3]=c;ans[4]=d;
                   ans[5]=e;ans[6]=f;ans[7]=g;ans[8]=h;ans[9]=i;                     
                  }
            }
   for(j=1;j<=9;j++)
    for(k=1;k<=ans[j];k++)
    cout<<j<<' ';
   return 0;
}

