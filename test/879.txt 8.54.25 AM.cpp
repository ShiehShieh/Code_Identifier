/*http://www.vijos.cn/Problem_Show.asp?id=1040*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 10010
#define MOD 1000000000
char a[ MAX_LEN ], b[ MAX_LEN ];
__int64 x[ MAX_LEN ], y[ MAX_LEN ], ans[ MAX_LEN ];
void copy( __int64* to, char* from )
{
	int i, j, k, tmp, l = strlen( from );
	for( i = l - 1, j = 0; i >= 0; i -= 9, j++ )
	{
		to[ j ] = 0;
		for( k = i, tmp = 1; k > i - 9 && k >= 0; k--, tmp *= 10 )
			to[ j ] += ( from[ k ] - '0' ) * tmp;
	}
}
int len( __int64* t )
{
	int i;
	for( i = MAX_LEN - 1; i >= 0 && t[ i ] == 0; i-- );
	return i;
}
void mul( __int64* a, __int64* b, __int64* ans )
{
	int lena = len( a );
	int lenb = len( b );
	int i, j;
	for( i = 0; i <= lena; i++ )
		for( j = 0; j <= lenb; j++ )
		{
			ans[ i + j ] += a[ i ] * b[ j ];
			if( ans[ i + j ] >= MOD )
			{
				ans[ i + j + 1 ] += ans[ i + j ] / MOD;
				ans[ i + j ] %= MOD; 
			}
		}
}
void output( __int64* t )
{
	int i, j, lent = len( t );
	printf("%I64d", t[ lent ]);
	for( i = lent - 1; i >= 0; i-- )
	{
		int size = 0;
		__int64 tmp = t[ i ];
		while( tmp )
		{
			tmp /= 10;
			size++;
		}
		for( j = 0; j < 9 - size; j++ )
			printf("0");
		printf("%I64d",t[ i ]);
	}
	printf("\n");
}
int main()
{
	scanf("%s %s", &a, &b);
	copy( x, a );
	copy( y, b );
	//output( x );
	//output( y ); 
	mul( x, y, ans );
	output( ans );
	return 0;
}
