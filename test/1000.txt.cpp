#include<stdio.h>
int n,ss,ee,p;
struct node{
    int s,e,w;
}a[10001];
int f[300000],w[20005],done[100001]={0};
void swap(int i,int j)
{
     node temp;
     temp=a[i];a[i]=a[j];a[j]=temp;
}
void qsort1(int left,int right)
{
     int i,last;
     if(left>=right) return;
     swap(left,(left+right)/2);
     last=left;
     for(i=left+1;i<=right;i++)
     if(a[i].s<a[left].s) swap(++last,i);
     swap(last,left);
     qsort1(left,last-1);
     qsort1(last+1,right);
}
void swap2(int i,int j)
{
     int temp;
     temp=w[i];w[i]=w[j];w[j]=temp;
}
void qsort2(int left,int right)
{
     int i,last;
     if(left>=right) return;
     swap2(left,(left+right)/2);
     last=left;
     for(i=left+1;i<=right;i++)
     if(w[i]<w[left]) swap2(++last,i);
     swap2(last,left);
     qsort2(left,last-1);
     qsort2(last+1,right);
}
void out(){
    int i;
    for(i=0;i<=ee*3;i++){
        printf("%d ",f[i]);
    }
    printf("\n");
}
void init(){
    n=0;
    int i,m,x,y,z,t;
    scanf("%d %d %d",&m,&ss,&ee);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&x,&y,&z);
        if(y<ss) continue;
        if(x>ee) continue;
        if(x<ss) x=ss;
        if(y>ee) y=ee;
        n++;
        a[n].s=x;
        a[n].e=y;
        a[n].w=z;
        w[n*2-1]=x;
        w[n*2]=y;
    }
    w[n*2+1]=ss;
    w[n*2+2]=ee;
    qsort1(1,n);
    qsort2(1,n*2+2);
    t=0;
    for(i=1;i<=n*2+2;i++){
        if(done[w[i]]==0){
            if(done[w[i]-1]) t++;
            else t+=2;
            done[w[i]]=t;
        }
        //printf("%d ",w[i]);
    }
    //printf("\n");
    ss=done[ss];
    ee=done[ee];
    for(i=1;i<=n;i++){
        a[i].s=done[a[i].s];
        a[i].e=done[a[i].e];
        //printf("%d %d\n",a[i].s,a[i].e);
    }
    //printf("%d %d\n",ss,ee);
    for(i=0;i<=ee;i++){
        f[i]=21474836;
    }
    f[ss-1]=0;
}
int min(int i,int j){
    return(i<j?i:j);
}
int find(int i,int l,int r,int x,int y){
    int t=21474836,j;
    for(j=x;j<=y;j++) if(f[j]<t) t=f[j];
    return(t);
}
int work(){
    int i,t;
    for(i=1;i<=n;i++){
        p=a[i].w;
        t=find(1,ss-1,ee,a[i].s-1,a[i].e-1);
        if(t>=21474836) continue;
        t=t+a[i].w;
        //change(1,ss-1,ee,a[i].e,t);
        f[a[i].e]=t;
        //out();
    }
    //return(find(1,ss-1,ee,ee,ee));
    t=f[ee];
    if(t>=21474836) t=-1;
    return(t);
}
int main(){
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    init();
    printf("%d",work());
}

