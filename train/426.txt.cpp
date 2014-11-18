#include <iostream>

using namespace std;

    int ord[256],n,flag;
    string dat[1001],tmp;
    char c;

bool small(string a,string b)
{
     for (int i=0;(a[i]!='\0')&&(b[i]!='\0');i++)
     {
         if (a[i]!=b[i]) return (ord[a[i]]<ord[b[i]]);
         else if ((a[i+1]=='\0')||(b[i+1]=='\0'))
         {
              return a[i+1]=='\0';
         }
     }
     return true;
}

int main()
{
    for (int i=1;i<=26;i++)
    {
        cin>>c;
        ord[c]=i;
    }
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>dat[i];
    cin>>flag;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            if (small(dat[i],dat[j])!=flag){
                                            tmp=dat[i];
                                            dat[i]=dat[j];
                                            dat[j]=tmp;
                                            }
    for (int i=1;i<=n;i++)
        cout<<dat[i]<<endl;
    return 0;
}
