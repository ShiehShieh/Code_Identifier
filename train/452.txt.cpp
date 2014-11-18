#include <cstdio>
int n,a[300],ans[300],f[300],max;
int main()
{
    scanf("%d\n",&n);
    for (int i=1;i<=n;i++){
      scanf("%d",&a[i]);    
    }
    for (int i=1;i<=n;i++){
      max=0;
      for (int j=i;j>=1;j--){
        if ((a[j]<a[i]) && (f[j]>max)){
          max=f[j];              
        }  
        f[i]=max+1;    
      }
    }
    for (int i=n;i>=1;i--){
      max=0;
      for (int j=i;j<=n;j++){
        if ((a[j]<a[i]) && (ans[j]>max)){
          max=ans[j];               
        }    
        ans[i]=max+1;
      }  
    }  
    max=0;
    for (int i=1;i<=n;i++){
      if (ans[i]+f[i]-1>max) max=ans[i]+f[i]-1;   
    }
    printf("%d\n",n-max);  
    return 0;
}

