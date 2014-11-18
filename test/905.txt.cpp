#include<iostream>
using namespace std;

int a[502][502];
int b[501][501];
int c[501][501];
int n,m;

int count(int x1,int y1,int x2,int y2){
    int i,j;
    int ans=0;
    for(i=x1;i<=x2;i++)
      for(j=y1;j<=y2;j++)ans=ans+a[i][j];
    return ans;
}

void start(){
     int i,j;
     cin>>n>>m;
     memset(a,0,sizeof(a));
     memset(b,0,sizeof(b));
     memset(c,0,sizeof(c));
     for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)cin>>a[i][j];
}

void dp(){
    int tmax;
    int temp;
    int min;
    int max=0;
    int i,j,p,q;
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++){
          if(a[i][j]!=0){
          for(p=i+1;p<=n;p++){
             if(a[p][j]!=0)b[i][j]++;
             else break;
          }
          for(q=j+1;q<=m;q++){
             if(a[i][q]!=0)c[i][j]++;
             else break;
          }
       }
    }
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++){
         temp=b[i][j];
         min=c[i][j];
         for(p=0;p<=temp;p++){
            if(c[i+p][j]<min)min=c[i+p][j];
            tmax=count(i,j,i+p,j+min);
            if(tmax>max)max=tmax;
            }
         }
    cout<<max;
}

int main(){
    start();
    dp();
} 

