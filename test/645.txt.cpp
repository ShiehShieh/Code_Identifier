// === Vijos P1446   By Mr.Tao
#include <iostream>
using namespace std;
#define MAX 200
short g[MAX][MAX] = {0};
int n, m, p;
int
main (void) {
// === Init ===
	cin >> n >> m;
	int i, j, k, a, b;
	for ( i = 0; i < m; ++i ) {
		cin >>  a >> b;
		g[a][b] = g[b][a] = 1;
	}
// === Floyd ===
	for ( k = 1; k <= n; ++k) 
	for ( i = 1; i <= n; ++i) 
	if ( i != k )
	for ( j = 1; j <= n; ++j) 
	    if ( k != j )
		if ( g[i][k] != 0 && g[k][j] != 0 )
        if ( g[i][j] > g[i][k] + g[k][j] || g[i][j] == 0)
			{ g[i][j] = g[j][i] = g[i][k] + g[k][j]; }
// === Ask And Answer ===
	cin >> p;
	int sum;
	for ( i = 0; i < p; ++i ) {
		cin >> a >> b;
		sum = 2;
		for ( j = 1; j <= n; ++j ) 
            if ( g[a][j] + g[j][b] == g[a][b] ) sum++;
		cout << sum << endl;
	}
return 0;
}


