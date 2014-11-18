#include "iostream"
#include "string"
using namespace std ;

int award ( int qm , int bj , char gb , char xb , int lw )
{
	int jj = 0 ;
	if ( qm > 80 && lw >= 1 ) jj += 8000 ;
	if ( qm > 85 && bj > 80 ) jj += 4000 ;
	if ( qm > 90 ) jj += 2000 ;
	if ( qm > 85 && xb == 'Y' ) jj += 1000 ;
	if ( bj > 80 && gb == 'Y' ) jj += 850 ;
	return jj ;
}

int main ( )
{
	int n , qm , bj , lw , jj0 , jj1 , jjz = 0 ;
	char gb , xb ;
	string name1 , name0 ;
	cin >> n ;
	for( int i = 0 ; i < n ; i ++ )
	{
		cin >> name1 >> qm >> bj >> gb >> xb >> lw ;
		jj1 = award ( qm , bj , gb , xb , lw ) ;
		if ( i == 0 )
		{
			jj0 = jj1 ;
			name0 = name1 ;
		}
		jjz += jj1 ;
		if ( jj1 > jj0 )
		{
			jj0 = jj1 ;
			name0 = name1 ;
		}
	}
	cout << name0 << endl << jj0 << endl << jjz << endl ;
	return 0 ;
}
