#include<iostream.h>
using std::cin;
using std::cout;
long l,s,t,m,n,i,j,w;
long a[101],b[101];
long c[10012];
int lin01(){
    cin>>l>>s>>t>>m;
    w=0;
    if (s==t) {w=1;j=0;
               for (i=1;i<=m;i++) {cin>>a[i];    
                                   if (a[i]%s==0) j++;
                                   }
               cout<<j;
               exit(0);                 
              }
 
    for (i=1;i<=m;i++) cin>>a[i];
    for (i=1;i<=m;i++)
      for (j=i+1;j<=m;j++) 
        if (a[i]>a[j]) {w=a[i];a[i]=a[j];a[j]=w;};
    if (a[1]>100) b[1]=100; else b[1]=a[1];
    for (i=2;i<=m;i++) {if ((a[i]-a[i-1])<100) b[i]=b[i-1]+a[i]-a[i-1];
                          else b[i]=b[i-1]+100;
                        };
    n=b[m]+10;
    return 0;
}
int lin02(){
    for (i=1;i<=n;i++){
        c[i]=101;
        for (j=s;j<=t;j++)
            if ( ((i-j)>=0) && (c[i-j]<c[i]) ) c[i]=c[i-j];
        for (j=1;j<=m;j++) 
            if (b[j]==i) c[i]=c[i]+1;
        }    
    return 0;
}
int main() {
    lin01();
    lin02();
    cout<<c[n];
    return 0;
}

