#include <stdio.h>
char s[2000];
int x[21],f1[21]={0},f2[21]={0},n=0;
int main(){
    gets(s);
    int i,j,k,m1=0,m2=0;
    i=k=0;
    while (s[i]!='\0'){
          if(s[i]==',') {x[++n]=k;k=0;}
          else k=k*10+s[i]-48;
          i++;
    }
    x[++n]=k;
    for (i=n;i>=1;i--){
        f1[i]=1;
        for (j=i+1;j<=n;j++) if(x[i]>=x[j]&&f1[i]<f1[j]+1) f1[i]=f1[j]+1;
    }
    for (i=1;i<=n;i++) if(f1[i]>m1) m1=f1[i];
    for (i=1;i<=n;i++){
        f2[i]=1;
        for (j=i-1;j>=1;j--) if(x[i]>=x[j]&&f2[i]<f2[j]+1) f2[i]=f2[j]+1;
    }
    for (i=1;i<=n;i++) if(f2[i]>m2) m2=f2[i];
    printf("%d,%d",m1,m2-1);
    //while(1);
    return 0;
}

