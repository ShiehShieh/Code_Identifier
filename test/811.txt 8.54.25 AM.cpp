#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
main()
{
      int N,i,j,sum;
      struct Class
      {
      char name[20];
      int Lscore,Cscore;
      char G,D;
      int paper;
      int sum;
      }student[100];
      scanf("%d", &N);
      for(i=0;i<N;i++)
          scanf("%s %d %d %c %c %d",&student[i].name,&student[i].Lscore,&student[i].Cscore,&student[i].G,&student[i].D,&student[i].paper);
      for(i=0;i<N;i++)
          {
          student[i].sum=0;
          if(student[i].Lscore>80&&student[i].paper>0)
              student[i].sum+=8000;
          if(student[i].Lscore>85&&student[i].Cscore>80)
              student[i].sum+=4000;
          if(student[i].Lscore>90)
              student[i].sum+=2000;
          if(student[i].Lscore>85&&student[i].D=='Y')
              student[i].sum+=1000;
          if(student[i].Cscore>80&&student[i].G=='Y')
              student[i].sum+=850;
          }
      for(sum=0,i=0;i<N;i++)
          sum+=student[i].sum;
      for(i=1,j=student[0].sum;i<N;i++)
          if(j<student[i].sum)
              j=student[i].sum;
      for(i=0;i<N;i++)
          if(student[i].sum==j)
          {
          puts(student[i].name);
          printf("%d\n",student[i].sum);
          printf("%d",sum);
          break;
          }
}

