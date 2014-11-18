#include<iostream>
using namespace std;

struct Point
{
int x;
int y;
}P[6001];

int n,a,b;
int r=0,up,down;

int cmpx1(const void *a,const void *b)
{
return (*(Point*)a).x - (*(Point*)b).x;
}

int cmpx2(const void *a,const void *b)
{
return (*(Point*)b).x - (*(Point*)a).x;
}

int cmpy(const void *a,const void *b)
{
return (*(Point*)a).y - (*(Point*)b).y;
}

int main()
{
cin>>a>>b>>n;
P[n+1].x=a;
P[n+1].y=0;
P[n+2].x=0;
P[n+2].y=b;
P[n+3].x=a;
P[n+3].y=b;
P[n+4].x=0;
P[n+4].y=0;
for(int i=1;i<=n;i++)
cin>>P[i].x>>P[i].y;
n+=4;
qsort(P+1,n,sizeof(P[0]),cmpy);
for(int i=1;i<n;i++)
r=max(r,(a)*(P[i+1].y-P[i].y));
qsort(P+1,n,sizeof(P[0]),cmpx1);
for(int i=1;i<n;i++)
{
up=0,down=b;
for(int j=i+1;j<=n;j++)
{
r=max(r,(down-up)*(P[j].x - P[i].x));
if(P[j].y == P[i].y)
break;
if(P[j].y > P[i].y)
down=min(down,P[j].y);
else
up=max(up,P[j].y);
if((down-up)*(a-P[i].x)<=r)
break;
}
}
qsort(P+1,n,sizeof(P[0]),cmpx2);
for(int i=1;i<n;i++)
{
up=0,down=b;
for(int j=i+1;j<=n;j++)
{
r=max(r,(down-up)*(P[j].x - P[i].x));
if(P[j].y == P[i].y)
break;
if(P[j].y > P[i].y)
down=min(down,P[j].y);
else
up=max(up,P[j].y);
if((down-up)*(a-P[i].x)<=r)
break;
}
}
cout<<r<<endl;
return 0;
}

