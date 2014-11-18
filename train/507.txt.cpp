#include<stdio.h>
int main()
{
    int i,j,v,n,max=0,k,a[30],f[20001];
    f[0]=1;
    scanf("%d",&v);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=1;i<20001;i++)
    f[i]=0;
    for(i=0;i<n;i++)
    {
        k=max;
        for(j=k;j>-1;j--)
        if(f[j]&&(j+a[i])<(v+1))
        {
            f[j+a[i]]=1;
            max=j+a[i];
            if(max==v)goto out;
            for(j--;j>-1;j--)
            if(f[j])f[j+a[i]]=1;
        }
    }
    out: printf("%d",v-max);
}
