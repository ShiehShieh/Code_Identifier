#include<iostream>
using namespace std;
int a[10001],n;
void qsort(int x,int y);
int find(int x,int y);
int main()
{
  int ans=0;
  int i,j;
  cin>>n;
  memset(a,0,sizeof(a));
  for(int i=1;i<=n;i++)
    cin>>a[i];
  qsort(1,n);
  i=1;
  while(i<n)
  {
  ans+=a[i]+a[i+1];
  a[i+1]+=a[i];
  int posi=find(a[i+1],i+1);
  int t=a[i+1];
  for(int s=i+1;s<posi;s++)
    a[s]=a[s+1];
  a[posi]=t;
  i++;             
  }
  cout<<ans<<endl;
  return 0;  
  
}
void qsort(int x,int y)
{
  int h=x,r=y,m=(h+r)>>1;
  int tmp=a[m];
  while(h<r)
  {
    while(a[h]<tmp) h++;
    while(a[r]>tmp) r--;
    if(h<=r){
             int tmp2=a[h];
             a[h]=a[r];
             a[r]=tmp2;
             h++;r--;
             }
  }
  if(r>x) qsort(x,r);
  if(h<y) qsort(h,y);
}  
int find(int x,int y)
{
  int s=n;
  while((a[s]>x)&&(s>y)) s--;
  return s;
}

