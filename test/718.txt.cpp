#include<iostream>
#include<iomanip>
using namespace std;

struct Edge
{
int a;
int b;
double c;
}E[100001];
int n,m=0,k=1;
int A[100001];
int Path[100002];

double r;

void setA()
{
for(int i=1;i<=n;i++)
A[i]=i;
}

int Find(int x)
{
Path[0]=0;
while(A[x]!=x)
{
Path[++Path[0]]=x;
x=A[x];
}
for(int i=1;i<=Path[0];i++)
A[Path[i]]=x;
return x;
}

void Union(int a,int b)
{
if(rand()%2)
A[Find(a)]=Find(b);
else
A[Find(b)]=Find(a);
}

int cmp(const void *a,const void *b)
{
if( (*(Edge*)a).c < (*(Edge*)b).c)
return -1;
return 1;
}

void Kus()
{
if(m<n-1)
{
r=-1;
return ;
}
setA();
r=0;
int fin=0;
for(int i=1;i<=m && fin<n-1;i++)
if(Find(E[i].a) != Find(E[i].b))
{
fin++;
r+=E[i].c;
Union(E[i].a,E[i].b);
}
if(fin<n-1)
r=-1;
}

int main()
{
srand((unsigned)time(NULL));
cout<<fixed<<setprecision(2);
double s;
cin>>s;
cin>>n;

while(scanf("%d %d %lf",&E[m+1].a,&E[m+1].b,&E[m+1].c)==3)
m++;

qsort(E+1,m,sizeof(E[0]),cmp);
Kus();
if(r<=s && r>0)
cout<<"Need "<<r<<" miles of cable"<<endl;
else
cout<<"Impossible"<<endl;

return 0;
}
