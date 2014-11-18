#include <iostream>
using namespace std;
int main()
{
    int n,st[100][4],i,w=0,m;
    char s[100][2];
    char na[100][21];
    char wm[21];
    for(i=0;i<100;i++)
    for(m=0;m<4;m++)
    st[i][m]=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
    cin>>na[i]>>st[i][0]>>st[i][1]>>s[i][0]>>s[i][1]>>st[i][2];
    }
    for(i=0;i<n;i++)
    {
                    if(st[i][0]>80&&st[i][2]>=1)
                    st[i][3]=st[i][3]+8000;
                    if(st[i][0]>85&&st[i][1]>80)
                    st[i][3]=st[i][3]+4000;
                    if(st[i][0]>90)
                    st[i][3]=st[i][3]+2000;
                    if(st[i][0]>85&&s[i][1]=='Y')
                    st[i][3]=st[i][3]+1000;
                    if(st[i][1]>80&&s[i][0]=='Y')
                    st[i][3]=st[i][3]+850;

    }
    for(i=0;i<n;i++)
                    if(st[i][3]>w)
                    {
                                  w=st[i][3];
                                  for(m=0;m<21;m++)
                                  wm[m]=na[i][m];
                    }
    cout<<wm<<"\n"<<w<<endl;
    w=0;
    for(i=0;i<n;i++)
    w=w+st[i][3];
    cout<<w;
}
