#include "stdio.h"

int a(int qm,int py,char gb,char xb,int lw)
{
	int sum=0;
	if(qm>=0&&qm<=100&&py>=0&&py<=100&&lw>=0&&lw<=10&&gb=='Y'||gb=='N'&&xb=='Y'||xb=='N')
    {
    if(qm>80&&lw>=1)
       sum+=8000;
    if(qm>85&&py>80)
       sum+=4000;
    if(qm>90)
       sum+=2000;
    if(qm>85&&xb=='Y')
       sum+=1000;
    if(py>80&&gb=='Y')
       sum+=850;
   
    }
    return sum;
} 

int main()
{
    int i,N,zq=0,xbiao,qm,py,lw,mag,cj[100]={0};
    char xm[100][20]={'\0'},gb,xb;
    scanf("%d",&N);
    if(N>=1&&N<=100)
    {
    for(i=0;i<N;i++)
      {
        scanf("%s %d %d %c %c %d",&xm[i],&qm,&py,&gb,&xb,&lw);
        cj[i]=a(qm,py,gb,xb,lw);
      }
    mag=cj[0];
    for(i=1;i<N;i++)
        {
          if(mag<cj[i])
            {
              mag=cj[i];
              xbiao=i;
             }
         }
    for(i=0;i<N;i++)
       zq+=cj[i];
    printf("%s\n%d\n%d\n",xm[xbiao],cj[xbiao],zq);
    }
    return 0;
}
