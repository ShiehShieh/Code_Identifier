#include<iostream>
using namespace std;
int x[60],y[60],k,n,lx=0,ly=0;
int ax[60],ay[60];
int hx[510],hy[510];
void init()
{
 memset(hx,0,sizeof(hx));
 memset(hy,0,sizeof(hy));
 cin>>n>>k;
 for (int i=1;i<=n;i++)
 {
 int xt,yt;
 cin>>xt>>yt;
 hx[xt]=1;ax[i]=xt;
 hy[yt]=1;ay[i]=yt;
 }
 for (int i=0;i<=500;i++)
 {
 if (hx[i]) {lx++;x[lx]=i;hx[i]=lx;}
 if (hy[i]) {ly++;y[ly]=i;hy[i]=ly;}
 }
 return ;
}
long search(int x1,int x2,int y1,int y2,int kn)
{
 int xmax=x1,xmin=x2,ymax=y1,ymin=y2;
 for (int i=1;i<=n;i++)
 if (hx[ax[i]]<=x2&&hx[ax[i]]>=x1&&hy[ay[i]]<=y2&&hy[ay[i]]>=y1)
 {
 if (hx[ax[i]]>xmax) xmax=hx[ax[i]];
 if (hx[ax[i]]<xmin) xmin=hx[ax[i]];
 if (hy[ay[i]]>ymax) ymax=hy[ay[i]];
 if (hy[ay[i]]<ymin) ymin=hy[ay[i]];
 }
 x1=xmin;x2=xmax;y1=ymin;y2=ymax;
 if (kn==1) return (x[x2]-x[x1])*(y[y2]-y[y1]);
 long temp=250000,t;
 for (int kx=1;kx<kn;kx++)
 {
 for (int i=x1;i<x2;i++)
 {
 t=search(x1,i,y1,y2,kx)+search(i+1,x2,y1,y2,kn-kx);
 if (temp>t) temp=t;
 }
 for (int i=y1;i<y2;i++)
 {
 t=search(x1,x2,y1,i,kx)+search(x1,x2,i+1,y2,kn-kx);
 if (temp>t) temp=t;
 }
 }
 return temp;
}
main()
{
init();
cout<<search(1,lx,1,ly,k);
return 0;
}
