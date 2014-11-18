#include <iostream>

using namespace std;

    int t[3000],res=0,m,n,k,l,d,x[3000],y[3000],p[3000],q[3000],dat[3000];
    
void swap(int &x,int &y)
{
     int tmp=x;
     x=y;
     y=tmp;
}
    
void sort(int l,int r)
{
     int i=l,j=r,mid=dat[(i+j)/2];
     for (;;)
     {
         while (dat[i]>mid) i++;
         while (dat[j]<mid) j--;
         if (i<=j)
         {
                  swap(dat[i],dat[j]);
                  swap(t[i],t[j]);
                  i++;
                  j--;
         }
         if (i>j) break;
     }
     if (l<j) sort(l,j);
     if (i<r) sort(i,r);
}

int main()
{
    bool use[3000],flag;
    cin>>m>>n>>k>>l>>d;
    
    for (int i=1;i<=d;i++)
        cin>>x[i]>>y[i]>>p[i]>>q[i];
    memset(dat,0,sizeof(dat));
    for (int i=1;i<=d;i++)
        if (y[i]==q[i]) dat[min(x[i],p[i])]++;
    for (int i=1;i<=n;i++)
        t[i]=i;
    sort(1,n);
    memset(use,false,sizeof(use));
    for (int i=1;i<=k;i++)
        use[t[i]]=true;
    flag=false;
    for (int i=1;i<=n;i++)
        if (use[i]){
                    if (flag) cout<<" ";
                    flag=true;
                    cout<<i;
                    }
    cout<<endl;
    
    memset(dat,0,sizeof(dat));
    for (int i=1;i<=d;i++)
        if (x[i]==p[i]) dat[min(y[i],q[i])]++;
    for (int i=1;i<=m;i++)                    
        t[i]=i;
    sort(1,m);
    memset(use,false,sizeof(use));
    for (int i=1;i<=l;i++)
        use[t[i]]=true;
    flag=false;
    for (int i=1;i<=m;i++)
        if (use[i]){
                    if (flag) cout<<" ";
                    flag=true;
                    cout<<i;
                    }
    cout<<endl;

    return 0;
}

