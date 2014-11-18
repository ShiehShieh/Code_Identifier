#include <iostream>

using namespace std;

    int n,dat[100000],res[100000];
    
void sort(int l,int r)
{
     int i=l,j=r,mid=dat[(i+j)/2];
     for (;;)
     {
         while (dat[i]<mid) i++;
         while (dat[j]>mid) j--;
         if (i<=j){
                   int tmp=dat[i];
                   dat[i]=dat[j];
                   dat[j]=tmp;
                   i++;
                   j--;
                   }
         if (i>j) break;
     }
     if (l<j) sort(l,j);
     if (i<r) sort(i,r);
}

void make(int l,int r,int k)
{
     if (l>r) return;
     res[k]=dat[l];
     make(l+(r-l)/2+1,r,k*2);
     make(l+1,l+(r-l)/2,k*2+1);
}

int main()
{
    cin>>n;
    memset(dat,0,sizeof(dat));
    for (int i=1;i<=n;i++)
        cin>>dat[i];
    sort(1,n);
    make(1,n,1);
    cout<<res[1];
    for (int i=2;i<=n;i++)
        cout<<" "<<res[i];
    cout<<endl;
    return 0;
}

