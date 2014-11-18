#include<cstdio>
int main(){
    int t[210]={0},b[30010],w,x,m,ans=0,i,j;
    scanf("%d%d",&w,&x);
    for(i=0;i<x;i++){
          scanf("%d",&j);
          t[j]++;
          }
    for(i=0,m=0;i<200;i++)
          for(j=0;j<t[i];j++){
                b[m]=i;
                m++;
                }
    for(i=0,j=m-1;i<=j;){
          if(b[i]+b[j]<=w){
               ans++;
               i++;
               j--;
               }
          else{
               ans++;
               j--;
               }
          }
    printf("%d",ans);
    return 0;
}

