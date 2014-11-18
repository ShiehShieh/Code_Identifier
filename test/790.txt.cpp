#include<cstdio>
#include<cmath>
#include<cstring>
double numble,circle[1000];
double pow1(int n)
{
       if(n==0)return 1;
       else return pow1(n-1)*10;
       }
double confuse(double num){
       char ch[150];
       int temp;
       double max=0,min=0;
       sprintf(ch,"%.0f",num);
       int i,j,k;
       k=strlen(ch);
       for(i=0;i<k;i++)
       {
                       for(j=0;j<k-i-1;j++)
                       if(ch[j]>ch[j+1])
                       {
                                        temp=ch[j];
                                        ch[j]=ch[j+1];
                                        ch[j+1]=temp;
                                        }
       }
       for(i=0;i<k;i++)
       {
                       max+=pow1(i)*(ch[i]-'0');
                       min+=pow1(k-i-1)*(ch[i]-'0');
                       }
                       return max-min;
                       }
int check_print(int i)
{
    int j;
    for(j=0;j<i;j++)
    {
                    if(circle[j]==circle[i])break;
                    }
                    if(j==i)return 0;
                    else 
                    {
                         for(;j<i;j++)printf("%.0lf ",circle[j]);
                         printf("\n");
                         return 1;
                         }
                         }
                         
void work(){
     int i=0;
     for(i=0;;i++)
     {
                  circle[i]=numble;
                  if(check_print(i)==1)break;
                  else numble=confuse(numble);
                  }
                  }
int main()
{
    while(1)
    {
            if(scanf("%lf",&numble)==-1)break;
            else
            {
                work();
                }
                }
}
