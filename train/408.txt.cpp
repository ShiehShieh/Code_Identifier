#include<iostream>
using namespace std;
int min1(int a,int b)
{
    if(a>b)
        a=b;
    return a;
}
int main()
{
    int m,n,k,l,d;
    int a[4],a1[1005]={0},b1[1005]={0},i,j,ma,mai,s1[1005]={0},s2[1005]={0};
    cin>>m>>n>>k>>l>>d;
    for(i=0;i<d;i++)
    {
        cin>>a[0]>>a[1]>>a[2]>>a[3];
        if(a[0]==a[2])
            a1[min1(a[1],a[3])-1]++;
        else
            b1[m-min1(a[0],a[2])]++;
    }
    for(i=0;i<k;i++)
    {
        ma=0;
        for(j=0;j<m;j++)
            if(b1[j]>=ma)
            {
                ma=b1[j];
                mai=j;
            }
        b1[mai]=0;
        s1[i]=m-mai;
    }
    for(i=0;i<k-1;i++)
        for(j=i+1;j<k;j++)
            if(s1[i]>s1[j])
                swap(s1[i],s1[j]);
    cout<<s1[0];
    for(i=1;i<k;i++)
        cout<<" "<<s1[i];
    cout<<endl;
    for(i=0;i<l;i++)
    {
        ma=0;
        for(j=0;j<n;j++)
            if(a1[j]>=ma)
            {
                ma=a1[j];
                mai=j;
            }
        a1[mai]=0;
        s2[i]=mai+1;
    }
    for(i=0;i<l-1;i++)
        for(j=i+1;j<l;j++)
            if(s2[i]>s2[j])
                swap(s2[i],s2[j]);
    cout<<s2[0];
    for(i=1;i<l;i++)
        cout<<" "<<s2[i];
    cout<<endl;
    return 0;
}
