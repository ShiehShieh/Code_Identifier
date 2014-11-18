#include <iostream>
using namespace std;

int t[21][21][21];

int main()
{
    int a,b,c,i,j,k,s;
    cin>>a>>b>>c;
    for (i=0;i<=20;i++)
    {
        for (j=0;j<=20;j++)
        {
            for (k=0;k<=20;k++)
            {
                if (i==0||j==0||k==0)
                {
                   t[i][j][k]=1;
                }
                else if (i<j&&j<k)
                {
                     t[i][j][k]=t[i][j][k-1]+t[i][j-1][k-1]-t[i][j-1][k];
                }
                else
                {
                    t[i][j][k]=t[i-1][j][k]+t[i-1][j-1][k]+t[i-1][j][k-1]-t[i-1][j-1][k-1];
                }
            }
        }
    }
    while (!(a==-1&&b==-1&&c==-1))
    {
          if (a<=0||b<=0||c<=0)
          {
             s=1;
          }
          else if (a>20||b>20||c>20)
          {
             s=t[20][20][20];
          }
          else
          {
              s=t[a][b][c];
          }
          cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<s<<endl;
          cin>>a>>b>>c;
    }
    return 0;
}

