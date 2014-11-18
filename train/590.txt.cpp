#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int map[50][50],n;
long val[50][50],max;
int main(){
    int i,j,p,q,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&map[i][j]);
    memset(val,0,sizeof(val)),max=0;
    while(1){
         p=-1;
         for(i=0;i<n;i++)for(j=0;j<n;j++)
            if(map[i][j]>0&&(p<0||map[i][j]>map[p][q]))
                p=i,q=j;
         if(p<0)break;
         for(i=0;i<n;i++)for(j=0;j<n;j++)if(map[p][q]>map[i][j]&&map[i][j]>0){
              k=abs(p-i)+abs(q-j),k*=k;
              if(val[i][j]<val[p][q]+k)val[i][j]=val[p][q]+k;                            
              if(val[i][j]>max)max=val[i][j];
              }
         map[p][q]=0;
         }
    printf("%ld\n",max);
    return 0;
    }

