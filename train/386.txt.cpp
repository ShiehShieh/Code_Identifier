#include <iostream>
using namespace std;

typedef struct {
        int w,l,r;
        }TreeDP;
        
int n,m;
int f[301][301]={0};
TreeDP a[301];

int Tree_DP(int father,int point)
{
     if (f[father][point]>0) return f[father][point];
     if (point==0) return 0;
     int maxx,i;
     maxx=0;
     if (a[father].r!=-1) maxx=Tree_DP(a[father].r,point);
     for (i=0; i<=point-1; i++)
         if ((a[father].l!=-1 || i==0) && (a[father].r!=-1 || point-i-1==0))
             if (Tree_DP(a[father].l,i)+Tree_DP(a[father].r,point-i-1)+a[father].w>maxx)
                 maxx=Tree_DP(a[father].l,i)+Tree_DP(a[father].r,point-i-1)+a[father].w;
     f[father][point]=maxx;
     return maxx;
}


int main()
{
    cin >> n >> m;
    int i,j,l,wi;
    for (i=0; i<=n; i++) a[i].l=a[i].r=-1;
    
    /*Built 2-Tree*/
    for (i=1; i<=n; i++)
    {
        cin >> l >> wi;
        a[i].w=wi;
        if (a[l].l==-1) a[l].l=i;
        else 
        {
            j=a[l].l;
            while (a[j].r!=-1) j=a[j].r;
            a[j].r=i;
        }
    }
    
    cout << Tree_DP(0,m+1);
    
    return 0;
}
