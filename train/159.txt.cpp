#include <iostream>
using namespace std;

void QSort (int L[],int low,int high);
int Partition (int L[],int low,int high);

void QuickSort (int L[],int n)
{
     QSort(L,0,n);
}

void QSort (int L[],int low,int high) 
{
     int pivotloc;
     if (low<high)
     {
        pivotloc=Partition(L,low,high);
        QSort (L,low,pivotloc-1); 
        QSort (L,pivotloc+1,high);          
     }
}

int Partition (int L[],int low,int high)
{
    int pivotkey;
    int temp;
    pivotkey=L[low];     
    while (low<high)
    {
          while (low<high&&L[high]>=pivotkey)
          {
                --high;
          }
          temp=L[low];
          L[low]=L[high];
          L[high]=temp;           
          while (low<high&&L[low]<=pivotkey)
          {
                ++low;
          }
          temp=L[low];
          L[low]=L[high];
          L[high]=temp;          
    }
    return low;                
} 

int main()
{
      int a[10000],n,i,j,t,p=1,s=0;
      cin>>n;
      for (i=0;i<n;i++)
      {
          cin>>a[i];
      }
      QuickSort(a,n-1);
      for (i=0;i<n-1;i++)
      {
          a[i+1]+=a[i];
          s+=a[i+1];
          for (j=i+1;a[j]>a[j+1]&&j<n-1;j++)
          {
              t=a[j];
              a[j]=a[j+1];
              a[j+1]=t;
          }
      }
      cout<<s<<endl;
      return 0;
} 

