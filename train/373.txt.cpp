# include<iostream>
using namespace std;

int job[401];
int machine[21][21],time_need[21][21];
int t[21][2001];
int step[21],finish[21];

int main()
{
    int i,j,k,m,n,spare;
    cin>>m>>n;
    int max=-1;
    for(i=1;i<=m*n;i++)
       cin>>job[i];
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
           cin>>machine[i][j];
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
           cin>>time_need[i][j];//init
           
    for(i=1;i<=m*n;i++)
    {
        step[job[i]]++;
        spare=0;
        for(j=finish[job[i]]+1;;j++)
        {
            if(t[machine[job[i]][step[job[i]]]][j])
               spare=0;
            else spare++;
            if(spare>=time_need[job[i]][step[job[i]]])break;
        }
        for(k=j-spare+1;k<=j;k++)
        {
            t[machine[job[i]][step[job[i]]]][k]=1;
        }
        finish[job[i]]=j;
        if(j>max)
           max=j;
    }
    cout<<max;
    return 0;
}
