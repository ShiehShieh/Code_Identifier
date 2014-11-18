#include<stdio.h>
#include<iostream>
int n,m,t;
int map[1001][1001],f[1001][1001],ans,mins,minnow;
int min(int a,int b){
    if(a<=b)return a;
    return b;
    }
int main(){
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    scanf("%d%d%d",&m,&n,&t);
    int i,j,k;
    for(i=1;i<=m;i++)
       for(j=1;j<=n;j++){
                         scanf("%d",&map[j][i]);
                         f[i][j]=0;
                         }
    mins=2147483647;
    for(i=1;i<=n;i++){
                      f[1][i]=map[i][1];
                      if(f[1][i]<mins)mins=f[1][i];
                      }
    for(i=2;i<=m;i++){
                      minnow=2147483647;
                      for(j=1;j<=n;j++){
                                        f[i][j]=min(f[i-1][j]+map[j][i],mins+t+map[j][i]);
                                        if(f[i][j]<minnow)minnow=f[i][j];
                                        }
                      mins=minnow;
                      }
    printf("%d\n",mins);
    return 0;
    }

