#include<iostream>
#include<limits>
using namespace std;
int n;
long long x[201],y[201],date[101][4];
bool map[201][201];
void insert(int i,int k)
{
     if(k==1&&x[i]<x[i-1]){
                            int j=i-1;
                            x[0]=x[i];
                            do{
                               x[j+1]=x[j];
                               j--;     
                              }while(x[0]<x[j]);
                            x[j+1]=x[0];
                            }
      if(k==2&&y[i]<y[i-1]){
                            int j=i-1;
                            y[0]=y[i];
                            do{
                               y[j+1]=y[j];
                               j--;     
                              }while(y[0]<y[j]);
                            y[j+1]=y[0];  
                            }
}
void init()
{
     int i,j;
     cin>>n;
     x[0]=LONG_LONG_MIN;
     y[0]=LONG_LONG_MIN;
     for(i=1;i<=n;i++)
     {
      cin>>date[i][0]>>date[i][1]>>date[i][2]>>date[i][3];
      x[i*2-1]=date[i][0];insert(i*2-1,1);  
      x[i*2]=date[i][2];insert(i*2,1);
      y[i*2-1]=date[i][1];insert(i*2-1,2);
      y[i*2]=date[i][3];insert(i*2,2);
     }    
     for(i=1;i<2*n;i++)for(j=1;j<2*n;j++)map[i][j]=false;
  }
void cover()
{
     int i,j,k;
     for(k=1;k<=n;k++)
       for(i=1;i<2*n;i++)
          for(j=1;j<2*n;j++) 
           if(x[i]>=date[k][0]&&y[j]>=date[k][1]&&date[k][2]>=x[i+1]&&date[k][3]>=y[j+1])
           map[i][j]=true;          
}
void outside()
{
     long long sum;
     int i,j;
     sum=0;
     for(i=1;i<2*n;i++)
      for(j=1;j<2*n;j++)
      if(map[i][j])
      sum+=(x[i+1]-x[i])*(y[j+1]-y[j]);
     cout<<sum;
 }
int main()
{
    init();
    cover();
    outside();
    return 0;
}

