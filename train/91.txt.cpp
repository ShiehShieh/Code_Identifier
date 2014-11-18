#include <iostream>
#include <cmath>

using namespace std;

struct node
{
	int x,y;
};

int m,n;
int k;
node a[1001];
int f[1001];

bool cmp(node a,node b)
{
	return (a.x < b.x || a.x == b.x && a.y < b.y);
}

int input()
{
	int i;
	cin >> n >> m;
	cin >> k;
	for (i = 1;i <= k;i++)
		cin >> a[i].x >> a[i].y; 
}

int init()
{
	int i;
	a[0].x = 0;
	a[0].y = 0;
	sort(a + 1,a + k + 1,cmp);
	for (i = 0;i <= k;i++)
		f[i] = 0;
}

int max_len()
{
	int i,j;
	for (i = 1;i <= k;i++)
		for (j = 0;j < i;j++)
			if (a[i].x > a[j].x && a[i].y > a[j].y)
				f[i] = max(f[i],f[j] + 1); 
	j = 0;
	for (i = 1;i <= k;i++)
		j = max(j,f[i]);
	return j;
}

double result()
{
	double total;
	total = m + n;
	total -= max_len() * (2 - sqrt(2));
	total *= 100;
	return total;
}


main()
{
	{
		input();
		init();
		printf("%0.0f\n",result());
	}
}

