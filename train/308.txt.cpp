#include<iostream>
using namespace std;
int a[400],b[20][20],c[20][20],o[20],t[20];
bool d[20][2001]; 
int main()
{
    int m,n,i,j,k,js=0,max=0;
    cin>>m>>n;
    memset(d,true,sizeof(d)); 
    for(i=0;i<20;i++){o[i]=1;t[i]=1;} 
    for(i=1;i<=m*n;i++)
                       cin>>a[i]; 
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
                     cin>>b[i][j]; 
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
                     cin>>c[i][j];
    for(i=1;i<=m*n;i++){js=0; 
    for(j=t[a[i]];j<=2000;j++)
    {  
                        if(d[b[a[i]][o[a[i]]]][j]==true)
                        {
                                                        js++;
                                                        if(js>=c[a[i]][o[a[i]]]){ 
                                                        for(k=j-js+1;k<=j;k++)
                                                        d[b[a[i]][o[a[i]]]][k]=false;
                                                        t[a[i]]=j+1; 
                                                        break;} 
                        }
                        if(d[b[a[i]][o[a[i]]]][j]==false)js=0; 
    }
    o[a[i]]++; 
    if(max<j)max=j;}
    cout<<max;  
    return 0; 
} 

