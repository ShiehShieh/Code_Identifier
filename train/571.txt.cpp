#include	<iostream>
#include	<fstream>

using namespace std;

int	n;
int	mid[100000];

void	turn( int num , int out[] )
{
	int	temp = num;
	int	group[10000];
	int	t = 1;

	while( temp )
	{
		group[t ++] = temp % 10;
		temp /= 10;
	}
	t --;
	out[0] = t;
	for( int	i = 1 ; i <= t ; i ++ )
		out[i] = group[t - i + 1];

	return ;
}
void	mult( int a[] , int b[] , int out[] )
{
	int	temp[100000];
	int	lena = a[0];
	int	lenb = b[0];
	int	leno = lena + lenb;

	memset( temp , 0 , sizeof( temp ) );

	for( int	i = 1 ; i <= lena ; i ++ )
		for( int	j = 1 ; j <= lenb ; j ++ )
			temp[i + j] += a[i] * b[j];
	for( int	i = leno ; i >= 1 ; i -- )
	{
		temp[i - 1] += temp[i] / 10;
		temp[i] %= 10;
	}

	out[0] = leno;
	for( int	i = leno ; i >= 1 ; i -- )
		out[i] = temp[i];

	return ;
}
void	out( int output[] )
{
	int	t = 1;

	while( output[t] == 0 )
	{
		t ++;
		if( t > output[0] )
		{
			cout << 0 << endl;
			return ;
		}
	}

	for( int	i = t ; i <= output[0] ; i ++ )
		cout << output[i];
	cout << endl;

	return ;
}
int	main()
{
	mid[0] = 1 ; mid[1] = 1 ;

	cin >> n;

	int	cur = 2;
	int	total = 1;
	int	num[100000];

	while( n >= cur )
	{
		num[total ++] = cur;
		n -= cur;
		cur ++;
	}
	total --;
	for( int	i = total ; i >= total - n + 1 ; i -- )
		num[i] ++;

	for( int	i = 1 ; i <= total ; i ++ )
	{
		cout << num[i];
		if( i == total ) cout << endl;
		else cout << ' ';
	}

	for( int	i = 1 ; i <= total ; i ++ )
	{
		int	temp[100000];

		turn( num[i] , temp );
		mult( mid , temp , mid );
	}

	out( mid );










	return 0;
}
