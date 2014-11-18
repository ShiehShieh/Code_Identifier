#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int Min,i,j,k,t,n,cost[1010],way[1010],com[1010][1010];
bool in[1010];
int main()
{
  cin >> n;
  for (i=0;i<n;i++)
  {
    scanf("%d",&cost[i]);
    way[i] = 1;
    in[i] = 1;
  }
  while ( scanf("%d%d%d",&i,&j,&k)!=EOF )
   com[i][j] = com[j][i] = k+1;
  for (i=0;i<n;i++)
  {
    Min = 100000000;
    for (j=0;j<n;j++)
     if ( in[j] && Min>cost[j] )
     {
       Min = cost[j];
       k = j;
     }
    in[k] = 0;
    for (j=0;j<n;j++)
     if ( com[k][j]>0 )
     {
       t = com[k][j]-1;
       if ( cost[t]>cost[j]+cost[k] )
       {
         cost[t] = cost[j]+cost[k];
         way[t] = 0;
       }
       if ( cost[t]==cost[j]+cost[k] && (!in[j]) && (!in[k]) ) way[t] += way[j]*way[k];
     }
  }
  cout << cost[0] << ' ' << way[0] << endl;
  return 0;
}

