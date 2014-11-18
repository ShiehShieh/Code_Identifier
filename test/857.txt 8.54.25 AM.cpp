/*http://www.vijos.cn/Problem_Show.asp?id=1132*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 20
struct Node
{
	char data;
	int lchild;
	int rchild;
}node[ MAXN ];
char in[ MAXN ];
char post[ MAXN ];
int size, root;
void solve( int father, int s1, int e1, int s2, int e2 )
{
	int i;
	node[ father ].data = post[ e2 ];
	node[ father ].lchild = node[ father ].rchild = -1;
	for( i = s1; in[ i ] != post[ e2 ]; i++ );
	int ltree_size = i - s1;
	int rtree_size = e1 - i;
	if( ltree_size > 0 )
	{
		node[ father ].lchild =  ++size;
		solve( node[ father ].lchild, s1, s1 + ltree_size - 1 , s2, s2 + ltree_size - 1 );
	}
	if( rtree_size > 0 )
	{
		node[ father ].rchild = ++size;
		solve( node[ father ].rchild, i + 1, i + rtree_size, e2 - rtree_size, e2 - 1 );
	}
}
void preorder_travesal( int father )
{
	if( father < 0 )
		return ;
	printf("%c", node[ father ].data );
	preorder_travesal( node[ father ].lchild );
	preorder_travesal( node[ father ].rchild );
}
int main()
{
	scanf("%s %s", in, post);
	int len = strlen( in );
	size = root = 0;
	solve( root, 0, len - 1 , 0, len - 1 );
	preorder_travesal( root );
	printf("\n");
	return 0;
}





