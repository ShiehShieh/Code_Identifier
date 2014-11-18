#include <stdio.h>

typedef struct cord
{
	int time;
	int v;
}Cord;

main()
{
	Cord cords[102];
	int t,m;
	int i,j;
	int c[1002];

	for( i = 0; i <= 1001; i++ )
	{
		c[i] = 0;
	}

	scanf( "%d%d",&t,&m );
	for( i = 0; i < m; i++ )
	{
		scanf( "%d%d",&cords[i].time,&cords[i].v );
	}
	for( i = 0; i < m; i++ )
	{
		for( j = t; j >= cords[i].time; j-- )
		{
			if( c[j] < c[j-cords[i].time] + cords[i].v)
			{
				c[j] = c[j-cords[i].time] + cords[i].v;
			}
		}
	}
	printf( "%d",c[t] );
}
