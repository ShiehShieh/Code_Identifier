#include <iostream>

using namespace std;

double total;
double l;
double max_v;
double cost_per;
double a[101],b[101];
int n;
double min_money;

int v[9];
double vv[9];


int input()
{
	int i;
	cin >> l;
	cin >> max_v >> cost_per >> total;
	cin >> n;
	for (i = 1;i <= n;i++)
	{
		cin >> a[i] >> b[i];
	}
	n++;
	a[n] = l;
	b[n] = 0; 
}

int dfs(int k,double oil,double money)
{
	int i;
	double cost,buy;
	if (oil < 0) return 0;
	if (k == n)
	{
		/*cout << endl;
		for (i = 1;i <= k;i++)
			cout << v[i] << " ";
		cout << endl;
		for (i = 1;i <= k;i++)
			cout << vv[i] << " ";
		cout << endl;
		cout << money << endl;
		cout << endl;*/
		min_money = min(min_money,money);
		
		return 0;
	}
	cost = (a[k + 1] - a[k]) / cost_per;
	//v[k] = 0;
	//vv[k] = money;
	dfs(k + 1,oil - cost,money);
	if (oil < max_v / 2 || oil - cost < 0)
	{
		buy = b[k] * (max_v - oil) + 20; 
		//v[k] = 1;
		//vv[k] = money + buy;
		dfs(k + 1,max_v - cost,money + buy);
	}
	
}

int deal()
{
	min_money = 1e24;
	dfs(1,max_v - a[1] / cost_per,total);
	printf("%0.1f\n",min_money);
}

main()
{
	
	{
		input();
		deal();
	}
}

