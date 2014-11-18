#include <iostream>
using namespace std;

int main()
{
	int w[25] = {0};
	int v[25] = {0};
	int f[30000] = {0};
	int M = 0, N = 0;
	int i = 0, j = 0;
	while (cin>>N>>M)
	{
		for ( i = 1; i <= M; i++ )
		{
			cin >> w[i] >> v[i];
			v[i] = w[i]*v[i];
		}

		for ( i = 1; i <= M; i++ )
		{
			for ( j = N; j >= w[i]; j-- )
			{
				if ( f[j-w[i]]+v[i] > f[j] )
					f[j] = f[j-w[i]]+v[i];
			}
		}
		cout << f[N] << endl;

		for ( i = 0; i < N; i++ )
			f[i] = 0;
	}

	return 0;
}
