#include<cstdio>
using namespace std;
int a[25][25],b[50][25][25][25],c[8][3];
int main()
{  int n,max1,j11,j22,j33;    
    c[1][1]=-1;c[1][2]=-1; c[1][3]=-1;
    c[2][1]=0;c[2][2]=-1; c[2][3]=-1;
    c[3][1]=0;c[3][2]=0; c[3][3]=-1;
    c[4][1]=0;c[4][2]=0; c[4][3]=0;
    c[5][1]=-1;c[5][2]=0; c[5][3]=-1;
    c[6][1]=-1;c[6][2]=-1; c[6][3]=0;
    c[7][1]=-1;c[7][2]=0; c[7][3]=0;
    c[8][1]=0;c[8][2]=-1; c[8][3]=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
     for (int j=1;j<=n;j++)
       {scanf("%d",&a[i][j]);}
    b[1][1][1][1]=a[1][1];
    for (int t=2;t<=n;t++)
       for (int j1=1;j1<=t;j1++)
         for (int j2=1;j2<=t;j2++)
          for (int j3=1;j3<=t;j3++)
            {max1=0;
              for (int i=1; i<=8;i++)
                {
                if (b[t-1][j1+c[i][1]][j2+c[i][2]][j3+c[i][3]]>max1)
                      max1=b[t-1][j1+c[i][1]][j2+c[i][2]][j3+c[i][3]];
                } 
                if ((j1==j2) && (j2==j3))
                   {b[t][j1][j2][j3]=max1+a[j1][t+1-j1]; continue;}
                if ((j1==j2) || (j2==j3))
                   {b[t][j1][j2][j3]=max1+a[j1][t+1-j1]+a[j3][t+1-j3]; continue;}
                if (j1==j3)
                   {b[t][j1][j2][j3]=max1+a[j2][t+1-j2]+a[j3][t+1-j3]; continue;}   
                b[t][j1][j2][j3]=max1+a[j1][t+1-j1]+a[j2][t+1-j2]+a[j3][t+1-j3];            
            }                     
                     
                     
                     
     for (int t=n+1;t<=2*n-1;t++)
       for (int j1=n;j1>=t-n+1;j1--)
         for (int j2=n;j2>=t-n+1;j2--)
          for (int j3=n;j3>=t-n+1;j3--)
            {max1=0;
              j11=t+1-j1;
              j22=t+1-j2;
              j33=t+1-j3;
              for (int i=1; i<=8;i++)
              {
                if (b[t-1][j11+c[i][1]][j22+c[i][2]][j33+c[i][3]]>max1)
                      max1=b[t-1][j11+c[i][1]][j22+c[i][2]][j33+c[i][3]];  
               } 
                if ((j11==j22) && (j22==j33))
                   {b[t][j11][j22][j33]=max1+a[j11][t+1-j11]; continue;}
                if ((j11==j22) || (j22==j33))
                   {b[t][j11][j22][j33]=max1+a[j11][t+1-j11]+a[j33][t+1-j33]; continue;}
                if (j11==j33)
                   {b[t][j11][j22][j33]=max1+a[j22][t+1-j22]+a[j33][t+1-j33]; continue;} 
                b[t][j11][j22][j33]=max1+a[j11][t+1-j11]+a[j33][t+1-j33]+a[j22][t+1-j22];            
             }                   
      printf("%d",b[2*n-1][n][n][n]); 
                  
    return 0;}

