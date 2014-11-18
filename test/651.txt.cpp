#include<iostream.h>
bool a[15000];
long int b[101],f[15000];
long int n,s,t,m;
  void init()
  {
    cin>>n;
    cin>>s>>t>>m;
    for (int i=1;i<=m;i++) cin>>b[i];
    
  }
  void cl()
  {
     long int t1,t2,t3,i;
     long int p[150];
     for (t1=1;t1<=m-1;t1++)
      for (t2=t1+1;t2<=m;t2++)
      if (b[t1]>b[t2]) {t3=b[t1];b[t1]=b[t2];b[t2]=t3;}  
     int h=n-b[m];
     if (h>100) h=100;
     b[0]=0;
     for (i=1;i<=m;i++) 
     {
        p[i]=b[i]-b[i-1];
        if (p[i]>100) p[i]=100;    
     }
     for (i=1;i<=m;i++) b[i]=b[i-1]+p[i];
     n=b[m]+h;  
  }
  void dp()
  {
     long int i,j,h,k,l;
     for (i=1;i<=n+t-1;i++) a[i]=true;
     for (i=1;i<=n+t-1;i++) f[i]=101;
     for (i=1;i<=m;i++) a[b[i]]=false;
     f[0]=0;
     for (i=1;i<=n+t-1;i++)
     {
       if (a[i]==false)h=1; else h=0;  
       for (j=s;j<=t;j++)
         if (i-j>=0) if (f[i-j]+h<f[i])f[i]=f[i-j]+h;
     }
  }
  void wri()
  {
     int min=101,i;
     for (i=n;i<=n+t-1;i++) if (f[i]<min) min=f[i];
     cout<<min<<endl;    
  }
  void pp()
  { int i,j,h,k,l;
    l=0;
    for (i=1;i<=m;i++)
    if (b[i]%s==0) l++;
    cout<<l<<endl; 
  }
    int main()
    {
      init();
      if (s<t) {
      cl();
      dp();
      wri();    }
      else pp();
      
    }

