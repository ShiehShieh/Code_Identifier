#include <iostream>

using namespace std;

int m,n;

int a[101][101];
int f[101][101];

int input()
{
	int i,j;
	string s;
	cin >> m >> n;
	getline(cin,s);
	for (i = 1;i <= m;i++)
	{
		getline(cin,s);
		for (j = 0;j < m;j++)
			if (s[j] == '#')
				a[i][j + 1] = 1;
			else
				a[i][j + 1] = 0;
	}
	
}

int init()
{
	int i,j;
	for (i = 0;i <= m;i++)
		for (j = 0;j <= m;j++)
			f[i][j] = 0;
	for (i = 1;i <= m;i++)
		for (j = 1;j <= m;j++)
			f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
}

int result()
{
	int i,j,k,x,y;
	int maximum = 0;
	if (n > m)	return f[m][m];
	for (i = 1;i <= m - n + 1;i++)
		for (j = 1;j <= m - n + 1;j++)
		{
			x = f[i + n - 1][j + n - 1] + f[i - 1][j - 1] - f[i + n - 1][j - 1] - f[i - 1][j + n - 1];
			maximum = max(x,maximum);
		}
	return maximum;
	
}

int check()
{
	int i,j;
	for (i = 1;i <= m;i++)
	{
		for (j = 1;j <= m;j++)
			cout << a[i][j];
		cout << endl;
	}
	cout << endl;
	for (i = 1;i <= m;i++)
	{
		for (j = 1;j <= m;j++)
			cout << f[i][j];
		cout << endl;
	}
}

int main()
{
	input();
	init();
	cout << result() << endl;
	cin >> n;

}

