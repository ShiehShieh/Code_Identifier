#include<stdio.h>
#include<string>
int num[1001],n;
int div(int x)
{
 int i,j;
 j=0;
 for(i=1;i<=n;i++)
 {
  if(j+num[i]<x)j=10*(j+num[i]);
  else {
        j=j+num[i]-x*((j+num[i])/x); 
        j*=10;
       }
 }
 if(j>0)return 0;
 return 1;
}
int main()
{
    int i;
    char temp[1001];
    scanf("%s",temp);
    for(i=1;i<=strlen(temp);i++)num[i]=temp[i-1]-'0';
    n=strlen(temp);
    printf("%d\n",div(2));
    printf("%d\n",div(3));
    printf("%d\n",div(4));
    printf("%d\n",div(8));
    printf("1");
    return 0;
}

