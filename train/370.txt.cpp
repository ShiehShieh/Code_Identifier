#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int calculate(char *a)
{
    int result=0,score,pyscore,wenshu;
    char c[2];
    sscanf(a,"%*s %d %d %c %c %d",&score,&pyscore,&c[0],&c[1],&wenshu);
    
    if(score>80 && wenshu>=1)
      result+=8000;
    if(score>85 && pyscore>80)
      result+=4000;
    if(score>90)
      result+=2000;
    if(c[1]=='Y' && score > 85)
      result+=1000;
    if(c[0]=='Y' && pyscore > 80)
      result+=850;

    return result;
}

int main()
{
    int zuigao=0,result[100],total=0,i,j;
    char s[50]={0},name[50],c;
    scanf("%d%c",&i,&c);
    for(j=0;j<i;j++)
    {
        gets(s);
        result[j]=calculate(s);
        total+=result[j];
        
        if (result[j] > zuigao)
        {
            memset(name,0,sizeof(name));
            sscanf(s,"%s %*d %*d %*c %*c %*d",name);
            zuigao=result[j];
        }
        memset(s,0,sizeof(s));
    }
    printf("%s\n%d\n%d",name,zuigao,total);
    return 0;
}
