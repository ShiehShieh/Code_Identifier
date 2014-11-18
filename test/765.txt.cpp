#include <iostream>
using namespace std;

struct sort_struct
{long long number;/*号码*/
long long v; /* 权 */ 
}w[500001];

long long n,k;
long long e[11];

void qksort(long long b,long long e)
{register long long i,j;
register sort_struct key;
if (b<e)
  {i=b;
  j=e;
  key=w[i];
  while (i<j)
  {while (i<j&&((w[j].v<key.v)||(w[j].v==key.v&&w[j].number>key.number))) --j;
    w[i]=w[j];
  while (i<j&&((w[i].v>key.v)||(w[i].v==key.v&&w[i].number<key.number))) ++i;
    w[j]=w[i];
  }
  w[i]=key;
  qksort(b,i-1);
  qksort(i+1,e);  
  } 
}

void init()
{register long long i;
scanf("%d%d",&n,&k);
for (i=1;i<=10;i++)
  scanf("%d",&e[i]);
for (i=1;i<=n;i++)
  {scanf("%d",&w[i].v);
  w[i].number=i;
  }
}

void work()
{qksort(1,n);
register long long i;
for (i=1;i<=n;i++)
  w[i].v=w[i].v+e[(i-1)%10+1];
qksort(1,n);
}

void out()
{register long long i;
for (i=1;i<k;i++) 
  printf("%d ",w[i].number);
 printf("%d\n",w[k].number);
}

int main(void)
{init();
work();
if (k>0)out();
return 0;
}
