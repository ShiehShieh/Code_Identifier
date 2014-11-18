/*
ID: pxtian22
LANG: C++
PROG: clocks
*/
/*http://ace.delos.com/usacoprob2?a=MkENdljsTec&S=clocks*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAXN 300000
struct Que
{
	int state;
	int prev;
	int comm;
};
Que queue[ MAXN ];
bool visited[ MAXN ];
int command[ 9 ][ 6 ] = 
{ 
	{ 0, 1, 3, 4 , -1, -1 }, 
	{ 0, 1, 2, -1, -1, -1 }, 
	{ 1, 2, 4, 5, -1, -1 }, 
	{ 0, 3, 6, -1, -1, -1 }, 
	{ 1, 3, 4, 5, 7, -1 }, 
	{ 2, 5, 8, -1, -1, -1 }, 
	{ 3, 4, 6, 7, -1, -1 },
	{ 6, 7, 8, -1, -1, -1 },
	{ 4, 5, 7, 8, -1, -1 } 
};
void trans( int& s, int c )
{
	int bit1 = 1 << ( 2 * c ) ;
	int bit2 = 1 << ( 2 * c + 1 );
	if( ( ( s & bit1 ) > 0 ) && ( ( s & bit2 ) > 0 ) )
		s -= ( bit1 + bit2 );
	else
		s += bit1;
}
int bfs()
{
	memset( visited, 0, sizeof( visited ) );
	queue[ 0 ].prev = queue[ 0 ].comm = -1;
	visited[ queue[ 0 ].state ] = true;
	int head, tail, i, j;
	for( head = 0, tail = 1; head < tail; head++ )
	{
		int state = queue[ head ].state;
		for( i = 0; i < 9; i++ )
		{
			int tmp = state;
			for( j = 0; command[ i ][ j ] >= 0; j++ )
				trans( tmp, command[ i ][ j ] );
			if( !visited[ tmp ] )
			{
				visited[ tmp ] = true;
				queue[ tail ].state = tmp;
				queue[ tail ].prev = head;
				queue[ tail ].comm = i;
				if( tmp == 0 )
					return tail;
				tail++;
			} 
		}
	}
}
void output( int index )
{
	if( index <= 0 )
		return ;
	output( queue[ index ].prev );
	printf("%d ", queue[ index ].comm + 1 );
}
int main()
{
	//freopen("clocks.in", "r", stdin);
	//freopen("clocks.out", "w", stdout);
	int i, j;
	queue[ 0 ].state = 0;
	for( i = 0, j = 1; i < 9; i++, j <<= 2 )
	{
		int tmp;
		scanf("%d", &tmp);
		queue[ 0 ].state += tmp * j; 
	}
	output( bfs() );
	printf("\n");
	return 0;
}





