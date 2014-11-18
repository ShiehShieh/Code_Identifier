#include <iostream>

using namespace std;

    int n,u,d,dat[40000],len=0,res=0;
    string str;

void get(int l,int r,int deep)
{
     if (deep<d) return;
     if (deep<=u){
                  bool x0=false,x1=false;
                  for (int i=l;i<=r;i++)
                  {
                      x0=x0||(dat[i]==0);
                      x1=x1||(dat[i]==1);
                  }
                  if (x0&&x1) res+=1;
                  else if (x1) res+=2;
                  else res+=5;
                  }
     int mid=(l+r)/2;
     get(l,mid,deep-1);
     get(mid+1,r,deep-1);
}

int main()
{
    cin>>n>>u>>d>>str;
    u=min(u,n);
    for (int i=0;str[i]!='\0';i++) 
    {
        len++;
        dat[len]=(str[i]=='1');
    }
    get(1,len,n);
    cout<<res<<endl;
    return 0;
}

