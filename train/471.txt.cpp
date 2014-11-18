#include <iostream>
#include <cmath>

using namespace std;

const int MAX_N = 100;
int n , m;

struct Arr
{
    double data[ MAX_N + 2 ];
    double& operator[]( int ind ) {
        return data[ ind ];
    }
} equ[ MAX_N + 1 ];

void input()
{
    cin >> n; m = n + 1;
    for( int i = 1 ; i <= n ; ++ i ) {
        for( int j = 1 ; j <= m ; ++ j ) {
            cin >> equ[ i ][ j ];
        }
    }
}

void makeZero( int std , int cur )
{
    double k = equ[ cur ][ std ] / equ[ std ][ std ];
    for( int i = std ; i <= m ; ++ i ) {
        equ[ cur ][ i ] -= equ[ std ][ i ] * k;
    }
}

void process( int cur )
{
    int maxFrom = cur;
    for( int i = cur + 1 ; i <= n ; ++ i ) {
        if ( abs( equ[ maxFrom ][ cur ] ) < abs( equ[ i ][ cur ] ) ) {
            maxFrom = i;
        }
    }
    if ( maxFrom != cur ) {
        Arr t = equ[ cur ];
        equ[ cur ] = equ[ maxFrom ];
        equ[ maxFrom ] = t;
    }
    for( int i = cur + 1 ; i <= n ; ++ i ) {
        makeZero( cur , i );
    }
}

double ans[ MAX_N + 1 ];

void getAns( int cur )
{
    double rtn = equ[ cur ][ m ];
    for( int i = n ; i > cur ; -- i ) {
        rtn -= equ[ cur ][ i ] * ans[ i ];
    }
    rtn /= equ[ cur ][ cur ];
    if ( abs( rtn ) < 1e-6 ) rtn = 0; 
    ans[ cur ] = rtn;
}

int main()
{
    input();
    for( int i = 1 ; i <= n ; ++ i ) {
        process( i );
    }
    for( int i = n ; i >= 1 ; -- i ) {
        getAns( i );
    }
    for( int i = 1 ; i <= n ; ++ i ) {
        cout.precision( 0 );
        cout << fixed;
        cout << ans[ i ] << ( i == n ? "\n" : " " );
    }
}

