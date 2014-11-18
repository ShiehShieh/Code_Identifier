#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

float x[101],y[101];
float L,R;
int n,i,j;

int main()
{
    scanf("%d",&n);
    scanf("%f",&R);
    for(i=1;i<=n;i++)
        scanf("%f%f",&x[i],&y[i]);

    if (n==1) 
        printf("%.2f",2*3.1415*R);
    else
    {    
        for(i=1;i<n;i++)
            L=L+sqrt((x[i+1]-x[i])*(x[i+1]-x[i])+(y[i+1]-y[i])*(y[i+1]-y[i]));
        L=L+sqrt((x[n]-x[1])*(x[n]-x[1])+(y[n]-y[1])*(y[n]-y[1]))+2*3.1415*R;
        printf("%.2f",L);
    }

    return 0;
}
