#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,m,i,j,t,a[101][11]={0},o,q=0;
    int k[11]={0},k1[11][101]={0};
    short p[40000][11]={0},p1[40000]={0};
    int head=1,end=2;
    string s1[1024],s2="aaaaaaaaaa",s3="aaaaaaaaaa";
    s1[0]="aaaaaaaaaa";
    char ss;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
     for(j=1;j<=n;j++)
     {
      s3[j-1]='b';
      p[1][j]=-1;
      cin>>a[i][j];
      if(a[i][j]==1)
      {
       k[j]++;
       k1[j][k[j]]=i;
      }
     }
    }
    while(head!=end)
    {
     o=0;
     for(i=1;i<=n;i++)
     {
      if(p[head][i]==-1)
      {
       for(t=1;t<=k[i];t++)
       {
        s2="aaaaaaaaaa";
        for(j=1;j<=n;j++)
        {
         p[end][j]=p[head][j];
         if(a[k1[i][t]][j]==1&&p[head][j]==-1)
         {
          p[end][j]=0;
         }
         if(a[k1[i][t]][j]==-1&&p[head][j]==0)
         {
          p[end][j]=-1;
         }
         ss=p[end][j]+98;
         s2[j-1]=ss;
        }
        p1[end]=p1[head]+1;
        q++;
        s1[q]=s2;
        for(j=1;j<q;j++)
        {
         if(s1[j]==s2)
         {
          end--;
          q--;
          break;
         }
        }
        if(s2==s3)
        {
         o=1;
         break;
        }
        end++;
        if(end>=40000)
        {
         end=1;
        }
       }
      }
      if(o==1)
      {
       break;
      }
     }
     if(o==1)
     {
      cout<<p1[end];
      break;
     }
     head++;
     if(head>=40000)
     {
      head=1;
     }
    }
    if(o==0)
    {
     cout<<"The patient will be dead.";
    }
    return 0;
}
