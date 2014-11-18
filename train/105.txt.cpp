#include<iostream>
#include<fstream>
using namespace std ;
int n , a[3][101] ; 
int main()
{
    int  t , mark , i , sy , max=1 ; 
    cin >> n ;     
    for( i = 1 ; i <= n ; i++ ) 
        {
         cin >> a[0][i] ;
         a[1][i] = a[2][i] = 1 ; 
         for( t=i-1 ,mark=1 ; t>0 ;t-- )
              if( a[0][t] < a[0][i] && mark <= a[1][t] ) mark=a[1][t]+1; 
         a[1][i] = mark;
        } 
   for( i = n-1 ; i > 0 ; i-- ) 
        {
         for( t=i+1 , mark=1 ; t<=n ; t++ )
              if ( a[0][i] > a[0][t] && mark <= a[2][t] ) mark=a[2][t]+1 ;
         a[2][i] = mark ;
        }
   for( i = 1 ; i <= n ; i++ ) 
         if ( a[1][i] + a[2][i] > max ) max = a[1][i] + a[2][i];
   
   sy=n-max+1; 
   cout << sy << endl ;
  return 0; 
} 
