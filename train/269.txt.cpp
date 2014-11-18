#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    int n,temp,i,j;
    cin>>n;
    int a[n+1],b[n+1],c[n+1];
    for (i=1;i<=n;i++)
    {
      cin>>a[i];
      cin>>temp;
      b[i]=temp+a[i];
      cin>>temp;
      b[i]=b[i]+temp;
      c[i]=i;
    }    
    for (i=1;i<=n-1;i++)
    for (j=i+1;j<=n;j++)
    if (b[i]<b[j])
    {
       temp=b[i];
       b[i]=b[j];
       b[j]=temp;
       temp=a[i];
       a[i]=a[j];
       a[j]=temp;
       temp=c[i];
       c[i]=c[j];
       c[j]=temp;
    }
    for (i=1;i<=n;i++)
    {
        int e=i;
        int s=i;
        while(i<=n){
          if(b[i]==b[i+1])
            e=i+1;
          else
            break;
          i++;
        }
        if(e>s){
          for(int t=s;t<=e-1;t++)
          for(int w=t+1;w<=e;w++)
          if(a[t]<a[w]){
            temp=a[t];
            a[t]=a[w];
            a[w]=temp;
            temp=c[t];
            c[t]=c[w];
            c[w]=temp;
            
          }
          for(int v=s;v<=e;v++)
          {
            int ve=v;
            int vs=v;
            while(v<=e){
              if(a[v]==a[v+1])
                ve=v+1;
              else
                break;
              v++;
            }
            if(ve>vs){
              for(int vt=vs;vt<ve;vt++)
              for(int vw=vt+1;vw<=ve;vw++)
              if(c[vt]>c[vw]){
                temp=c[vt];
                c[vt]=c[vw];
                c[vw]=temp;
              }
            }
          }
        }
    }
    for (i=1;i<=5;i++)
    cout<<c[i]<<" "<<b[i]<<endl;
    return 0;
}
