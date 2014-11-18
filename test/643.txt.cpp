// === Vijos P1446   By Mr.Tao
#include <iostream>
using namespace std;
#define MAX 200
#define MAXINT 1000
short g[MAX][MAX];
short s[MAX], d[MAX*2]; //s是顶点访问标志， d是待访问顶点队列
int n, m, p;
int
main (void) {
// === Init ===
	cin >> n >> m;
	int i, j, k, a, b;
	for ( i = 1; i <= n; ++i ) 
        for ( j = 1; j <= n; ++j) 
            if ( i != j ) g[i][j] = MAXINT; else g[i][j] = 0;
	for ( i = 0; i < m; ++i ) {
		cin >>  a >> b;
		g[a][b] = g[b][a] = 1;
	}
// === Floyd-War ===
	for ( k = 1; k <= n; ++k) 
	for ( i = 1; i <= n; ++i) 
	for ( j = 1; j <= n; ++j) 
		if ( g[i][k] != MAXINT && g[k][j] != MAXINT && g[i][j] > g[i][k] + g[k][j] )
			{ g[i][j] = g[j][i] = g[i][k] + g[k][j]; }
// === Ask And Answer ===
	cin >> p;
	int x, y, sum;
	while ( p > 0 ) {
		cin >> a >> b;
		if ( a > b ) {int t = a; a = b; b = t;}
		memset ( s, 0, sizeof (s) );  
		memset ( d, 0, sizeof (d) );
		d[x=0] = b; 
		y = 1;
		s[b] = 1;
		sum = 1;
		while ( x < y ) {
			for ( i = 1; i <= n; ++i ) 
				if ( !s[i] && g[a][i] + g[i][d[x]] == g[a][d[x]] )
				{ 
				  s[i] = 1;
				  sum++; 
				  d[y++] = i;
				}
			x++;
		}
		cout << sum << endl;
		p--;
	}
return 0;
}


