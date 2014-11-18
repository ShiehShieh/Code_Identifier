#include<stdio.h>

int a[1501][1501]={0},cost[1501],f[1501][3],s[1501],g[1501]={0};






int minn(int a,int b){
    return a<b?a:b;
}

int min2(int a,int b,int c){
    a=a<b?a:b;
    return a<c?a:c;

}







int work(int x,int y){
    int i,j;
    if(f[x][y]>0)return f[x][y];
    if(y==1){
             for(i=1;i<=s[x];i++)
             f[x][y]+=minn(work(a[x][i],1),work(a[x][i],2));
             f[x][y]+=cost[x];
             return f[x][y];
             }
    if(y==2){
              for(i=1;i<=s[x];i++)
             f[x][y]+=minn(work(a[x][i],1),work(a[x][i],0));
            
             return f[x][y];
             }
    if(y==0){
             int min=2147483647,s1;
             for(i=1;i<=s[x];i++)
             {s1=work(a[x][i],1);
                     for(j=1;j<=s[x];j++)
                      if(j!=i)s1+=minn(work(a[x][j],1),work(a[x][j],0));
              if(s1<min)min=s1;
              }
             f[x][y]=min;
             return f[x][y];
             }
    }


main(){
              int n,i,k,j,go;
       scanf("%d",&n);
       for(i=1;i<=n;i++)
       {
             scanf("%d",&k);  
             scanf("%d %d",&cost[k],&s[k]);
             for(j=1;j<=s[k];j++)
             {scanf("%d",&a[k][j]);        
              g[a[k][j]]=1;
              }
              }
        for(i=1;i<=n;i++)
        if(g[i]==0){go=i;break;}
        int b;
        b=work(go,0);
        b=b<work(go,1)?b:work(go,1);
        printf("%d",b);
        }
              

