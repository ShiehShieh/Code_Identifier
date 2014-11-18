#include<iostream>
using namespace std;
main()
{
      bool map[16][16];
      memset(map,true,sizeof(map));
      int n,m,x,y;
      cin>>n>>m>>x>>y;
      if (x+2<=15) {
                   if (y+1<=15) map[x+2][y+1]=false;
                   if (y-1>=0) map[x+2][y-1]=false;
                   }
                   if (x-2>=0) {
                               if (y+1<=15) map[x-2][y+1]=false;
                               if (y-1>=0) map[x-2][y-1]=false;
                               }
                               if (x-1>=0) {
                                           if (y+2<=15) map[x-1][y+2]=false;
                                           if (y-2>=0) map[x-1][y-2]=false;
                                           }
                                           if (x+1<=15){
                                                        if (y+2<=15) map[x+1][y+2]=false;
                                                        if (y-2>=0) map[x+1][y-2]=false;
                                                        }
                                                        map[x][y]=false;
                                                        long f[16][16];
                                                        memset(f,0,sizeof(f));
                                                        f[0][0]=1;
                                                        for (int k=1;k<=n+m+1;k++)
                                                        for (int i=0;i<=k;i++)
                                                        if (i>n) break;
                                                        else if (map[i][k-i])
                                                        {
                                                             if (k-i>m) continue;
                                                             if (i>0) f[i][k-i]+=f[i-1][k-i];
                                                             if (k>i) f[i][k-i]+=f[i][k-i-1];
                                                             }
                                                             cout<<f[n][m]<<endl;
                                                             return 0;
                                                             }

