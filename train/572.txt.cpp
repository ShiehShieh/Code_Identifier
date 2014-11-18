#include<iostream>
using namespace std;
int mult(int a[],int ta)
{
  int i,j;
  j=0;
  for(i=0;i<ta;i++)
   {
    a[i]=a[i]*2+j;
    j=a[i]/10;
    a[i]%=10;
   }   
  if(j){a[ta]=j;return ta+1;}
  return ta;
}
int add(int a[],int ta)
{
  int i,j;
  a[0]+=1;
  j=a[0]/10;
  a[0]%=10;
  i=0;
  while(j){
           i++;           
           a[i]+=j;
           j=a[i]/10;
           a[i]%=10;
           }
  if(i==ta)return ta+1;
  return ta; 
}
int main()
{
  int i,a[250]={0},ta,n;
  cin>>n;
  a[0]=1;ta=1;
  for(i=2;i<=n;i++){
                    ta=mult(a,ta);
                    if(i%2)ta=add(a,ta);        
                    }
   for(i=ta-1;i>=0;i--)cout<<a[i];
   return 0;   
}

