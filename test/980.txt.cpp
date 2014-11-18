#include<iostream>
#include<cstring>
using namespace std;
#define N 100
#define M 20
int bij(int);
int a[N],b[N],c[N],m[N],n,big=0,z=0;
char name[N][M],bg[N],xb[N],first[N][M];
int main()
{
  cin>>n;
  for(int j=0;j<n;j++)
    cin>>name[j]>>a[j]>>b[j]>>bg[j]>>xb[j]>>c[j];
  for(int i=0;i<n;i++)
  {
    m[i]=0;
    if(a[i]>80&&c[i]>=1)
        m[i]+=8000;
    if(a[i]>85&&b[i]>80)
        m[i]+=4000;
    if(a[i]>90)
         m[i]+=2000;
    if(a[i]>85&&xb[i]=='Y')
         m[i]+=1000;
    if(b[i]>80&&bg[i]=='Y')
         m[i]+=850;
    z+=m[i];
    if(big<m[i])
      {
          big=m[i];
          strcpy(first[0],name[i]);
      }
  }
    cout<<first[0];
    cout<<"\n"<<big<<"\n"<<z;
}
