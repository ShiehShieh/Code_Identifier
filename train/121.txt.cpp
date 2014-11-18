#include <stdio.h>
#include <malloc.h>
const int maxn=1000,maxdot=6;
int *gap,*addgap,*g,n,domino[1001];
int abs(int x){
    return (x>0)?x:-x;
}
void read_data(){
     int i,a,b;
     scanf("%d",&n);
     for (i=1;i<=n;i++) {scanf("%d%d",&a,&b);domino[i]=a-b;}
}
void solve(){
     int max1,min1,i,j,k;
     gap=(int *)malloc(sizeof(int)*12001);
     addgap=(int *)malloc(sizeof(int)*12001);
     for (i=0;i<=12000;i++) gap[i]=addgap[i]=1000;
     gap[6000]=0;
     min1=max1=6000;
     for (i=1;i<=n;i++){
         for (j=min1;j<=max1;j++)
             if(gap[j]<1000)
               {k=j+domino[i];
                if(gap[j]<addgap[k]) addgap[k]=gap[j];
                k=j-domino[i];
                if(gap[j]+1<addgap[k]) addgap[k]=gap[j]+1;
                gap[j]=1000;
               }
         min1-=abs(domino[i]);
         max1+=abs(domino[i]);
         g=gap;gap=addgap;addgap=g;
         /*for (j=min1;j<=max1;j++) printf("i=%d j=%d value=%d\n",i,j-6000,gap[j]);
         printf("\n");*/
     }
}
void write_data(){
     int min1=1000,k=5999;
     do
     {k++;
      if(gap[k]<min1) min1=gap[k];
      if(gap[12000-k]<min1) min1=gap[12000-k];
     }while(min1>=1000);
     printf("%d",min1);
}
int main(){
    read_data();
    solve();
    write_data();
    //while(1);
    return 0;
}

