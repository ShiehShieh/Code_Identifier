#include<stdio.h>
#include<stdlib.h>
#include<string.h>
bool t;
int main(){
    int i,a[9];
    t=0;
    for(i=8;i>=0;i--)scanf("%d",a+i);
    for(i=8;i>=0;i--){
        if(a[i]!=0){
            if(a[i]>0){
                if(t)printf(" + ");
                if(a[i]!=1||i==0)printf("%d",a[i]);
                }
            if(a[i]<0){
                       if(t)printf(" - ");
                       else printf("-");
                       if(a[i]!=-1||i==0)printf("%d",-a[i]);
                       }
            if(i==0);
            else if(i==1)printf("x");
            else printf("x^%d",i);
            t=1;
            }
        }
    if(!t)printf("0");
    printf("\n");
    return 0;
    }

