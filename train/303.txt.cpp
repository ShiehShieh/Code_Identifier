#include<iostream.h>
using namespace std;
int main()
{
 	short int a[100],i,j,s,n;
 	char c;
 	for(n=0;cin>>a[n];n++)
 	    cin>>c;
    short int f[n],g[n],topf,topg;
    topf=topg=0;
    for(i=0;i<n;i++)
    {
		for(j=0;j<topf;j++)
		    if(f[j]<a[i]){f[j]=a[i];break;}
        if(j==topf)
           f[topf++]=a[i];
    }
    for(i=0;i<n;i++)
    {
		for(j=0;j<topg;j++)
		     if(g[j]>a[i]){g[j]=a[i];break;}
        if(j==topg) g[topg++]=a[i];
    }
    cout<<topf<<','<<topg-1<<endl;
}

