#include <iostream>
using namespace std;
#define lowbit(x) ((x)&(-(x)))
#define maxn 1050

int n,c[maxn][maxn];

inline void Add(int x,int y,int delta)
{
	for (;x<=n;x+=lowbit(x))
		for (int i=y;i<=n;i+=lowbit(i))
			c[x][i]+=delta;
}

inline int get(int x,int y)
{
	int res=0;
	for (;x>0;x-=lowbit(x))
		for (int i=y;i>0;i-=lowbit(i))
			res+=c[x][i];
	return res;
}

int main()
{
	scanf("%d",&n);
	for (int m;scanf("%d",&m) && m!=3;)
	{
		int x,y,k,x1,y1,x2,y2;
		if (m==1)
		{
			scanf("%d%d%d",&x,&y,&k);
			++x;++y;
			Add(x,y,k);
		}else
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			++x1;++y1;++x2;++y2;
			int t1=get(x2,y2)-get(x1-1,y2);
			int t2=get(x1-1,y1-1)-get(x2,y1-1);
			printf("%d\n",t1+t2);
		}
	}
	return 0;
}

