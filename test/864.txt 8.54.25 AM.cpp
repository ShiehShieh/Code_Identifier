/*http://www.vijos.cn/Problem_Show.asp?id=1501*/
#include <stdio.h>
#include <stdlib.h>
#define MAXN 40000
int n, u, d;
__int64 tot;
char bit[ MAXN ];
int sum0[ MAXN ], sum1[ MAXN ];
void dfs( int depth, int l, int r )
{
	if( depth < d )
		return ;
	if( depth >= d && depth <= u )
	{
		int num0 = sum0[ r ] - sum0[ l - 1 ];
		int num1 = sum1[ r ] - sum1[ l - 1 ];
		if( num0 > 0 && num1 > 0 )
			tot += 1;
		else if( num0 == 0 && num1 > 0 )
			tot += 2;
		else if( num0 > 0 && num1 == 0 )
			tot += 5;
	}
	int len = ( r - l + 1 ) / 2;
	dfs( depth - 1, l, l + len - 1 );
	dfs( depth - 1, r - len + 1, r );
}
int main()
{
	scanf("%d %d %d %s", &n, &u, &d, bit);
	int i, len = 1 << n;
	sum0[ 1 ] = 1 - ( bit[ 0 ] - '0' );
	sum1[ 1 ] = bit[ 0 ] - '0';
	for( i = 2; i <= len; i++ )
	{
		sum0[ i ] = sum0[ i - 1 ];
		sum1[ i ] = sum1[ i - 1 ];
		if( bit[ i - 1 ] == '0' )
			sum0[ i ]++;
		else
			sum1[ i ]++;  
	}
	tot = 0;
	dfs( n, 1, len );
	printf("%I64d\n", tot);
	return 0;
}





