#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#define max( a, b ) ( ( a ) > ( b ) ? ( a ) : ( b ) )
using namespace std;
class BigInteger
{
    const static int DN = 512;
    const static int F = 10000, FK = 4;
    int n[ DN ], len;
    bool negative;
    void add( const BigInteger& );
    void sub( const BigInteger&, int );
    void format();
    bool lessthan( const BigInteger&, int ) const;
public:
    BigInteger( int );
    BigInteger( char*, int );
    BigInteger& operator = ( int b ) { return *this = BigInteger( b ); }
    bool operator < ( const BigInteger& ) const;
    bool operator > ( const BigInteger& b ) const { return b < *this; };
    bool operator <= ( const BigInteger& b ) const { return !( *this > b ); }
    bool operator >= ( const BigInteger& b ) const { return !( *this < b ); }
    bool operator != ( const BigInteger& b ) const { return *this < b || *this > b; }
    bool operator < ( const int& b ) const { return *this < BigInteger( b ); }
    bool operator > ( const int& b ) const { return *this > BigInteger( b ); }
    bool operator <= ( const int& b ) const { return *this <= BigInteger( b ); }
    bool operator >= ( const int& b ) const { return *this >= BigInteger( b ); }
    bool operator != ( const int& b ) const { return *this != BigInteger( b ); }
    void operator += ( const BigInteger& );
    void operator -= ( const BigInteger& );
    void operator *= ( const BigInteger& );
    void operator /= ( const BigInteger& );
    void operator %= ( const BigInteger& b ) { *this -= *this / b * b; }
    BigInteger operator + ( const BigInteger& b ) const { BigInteger r = *this; r += b; return r; };
    BigInteger operator - ( const BigInteger& b ) const { BigInteger r = *this; r -= b; return r; };
    BigInteger operator * ( const BigInteger& b ) const { BigInteger r = *this; r *= b; return r; };
    BigInteger operator / ( const BigInteger& b ) const { BigInteger r = *this; r /= b; return r; };
    BigInteger operator % ( const BigInteger& b ) const { BigInteger r = *this; r %= b; return r; };
    void operator += ( const int& b ) { *this += BigInteger( b ); }
    void operator -= ( const int& b ) { *this -= BigInteger( b ); }
    void operator *= ( const int& );
    void operator /= ( const int& );
    void operator %= ( const int& b ) { *this -= *this / b * b; }
    BigInteger operator + ( const int& b ) const { BigInteger r = *this; r += b; return r; }
    BigInteger operator - ( const int& b ) const { BigInteger r = *this; r -= b; return r; }
    BigInteger operator * ( const int& b ) const { BigInteger r = *this; r *= b; return r; }
    BigInteger operator / ( const int& b ) const { BigInteger r = *this; r /= b; return r; }
    BigInteger operator % ( const int& b ) const { BigInteger r = *this; r %= b; return r; }
    BigInteger operator - () { BigInteger r = *this; r.negative = !negative; r.format(); return r; }
    friend BigInteger operator + ( int k, const BigInteger& b ) { return BigInteger( k ) + b; }
    friend BigInteger operator - ( int k, const BigInteger& b ) { return BigInteger( k ) - b; }
    friend BigInteger operator * ( int k, const BigInteger& b ) { return BigInteger( k ) * b; }
    friend BigInteger operator / ( int k, const BigInteger& b ) { return BigInteger( k ) / b; }
    friend BigInteger operator % ( int k, const BigInteger& b ) { return BigInteger( k ) % b; }
    void print() const;
};
BigInteger::BigInteger( int e = 0 )
{
    memset( n, 0, sizeof( n ) );
    len = 1;
    n[ 0 ] = e;
    while ( n[ len - 1 ] >= F )
    {
        n[ len ] += n[ len - 1 ] / F;
        n[ len - 1 ] %= F;
        ++len;
    }
}
BigInteger::BigInteger( char* str, int slen = -1 )
{
    memset( n, 0, sizeof( n ) );
    if ( !isdigit( *str ) )
    {
        ++str;
    }
    slen = slen == -1 ? strlen( str ) : slen;
    len = ( slen + FK - 1 ) / FK;
    for ( int i = 0; i < len; ++i )
    {
        int sum = 0;
        for ( int j = max( 0, slen - FK ); j < slen; ++j )
        {
            sum = sum * 10 + str[ j ] - '0';
        }
        n[ i ] = sum;
        slen -= FK;
    }
    format();
}
void BigInteger::format()
{
    for ( ; len > 1 && n[ len - 1 ] == 0; --len );
}
bool BigInteger::lessthan( const BigInteger& b, int bg = 0 ) const
{
    if ( len - bg != b.len )
    {
        return len - bg < b.len;
    }
    else
    {
        bool ret = false;
        for ( int i = len - bg - 1; i > -1; --i )
        {
            if ( n[ bg + i ] != b.n[ i ] )
            {
                ret = n[ bg + i ] < b.n[ i ];
                break;
            }
        }
        return ret;
    }
}
bool BigInteger::operator < ( const BigInteger& b ) const
{
        bool ret = false;
            ret = lessthan( b );
        return ret;
}
void BigInteger::add( const BigInteger& b )
{
    len = max( len, b.len );
    int r = 0;
    for ( int i = 0; i < len; ++i )
    {
        n[ i ] += b.n[ i ] + r;
        r = n[ i ] / F;
        n[ i ] %= F;
    }
    if ( r )
    {
        n[ len++ ] = r;
    }
    format();
}
void BigInteger::sub( const BigInteger& b, int bg = 0 )
{
    int length = len - bg;
    for ( int i = 0; i < length; ++i )
    {
        n[ i + bg ] -= b.n[ i ];
        if ( n[ i + bg ] < 0 )
        {
            n[ i + bg ] += F;
            --n[ i + bg + 1 ];
        }
    }
    format();
}
void BigInteger::operator += ( const BigInteger& b )
{
        add( b );
}
void BigInteger::operator -= ( const BigInteger& b )
{
        if ( b.lessthan( *this ) )
        {
            sub( b );
        }
        else
        {
            BigInteger r = b;
            r.sub( *this );
            *this = r;
            negative = !negative;
            format();
        }
}
void BigInteger::operator *= ( const BigInteger& b )
{
    BigInteger a = *this;
    memset( n, 0, sizeof( n ) );
    len += b.len;
    for ( int i = 0; i < a.len; ++i )
    {
        for ( int j = 0; j < b.len; ++j )
        {
            int k = i + j;
            n[ k ] += a.n[ i ] * b.n[ j ];
            if ( n[ k ] >= F )
            {
                n[ k + 1 ] += n[ k ] / F;
                n[ k ] %= F;
            }
        }
    }
    format();
}
void BigInteger::operator /= ( const BigInteger& b )
{
    BigInteger a = *this;
    len = max( 0, len - b.len + 1 );
    memset( n, 0, sizeof( n ) );
    for ( int i = len - 1; i > -1; --i )
    {
        int head = 0;
        int tail = F - 1;
        int times = 0;
        while ( head <= tail )
        {
            int mid = head + tail >> 1;
            if ( !( a.lessthan( b * mid, i ) ) )
            {
                times = mid;
                head = mid + 1;
            }
            else
            {
                tail = mid - 1;
            }
        }
        a.sub( b * times, i );
        n[ i ] = times;
    }
    if ( len == 0 )
    {
        ++len;
    }
    format();
}
void BigInteger::operator *= ( const int& b )
{
    int r = 0;
    for ( int i = 0; i < len; ++i )
    {
        n[ i ] = n[ i ] * b + r;
        r = n[ i ] / F;
        n[ i ] %= F;
    }
    while ( r )
    {
        n[ len++ ] = r % F;
        r /= F;
    }
    format();
}
void BigInteger::operator /= ( const int& b )
{
    int r = 0;
    for ( int i = len - 1; i > -1; --i )
    {
        n[ i ] += r * F;
        r = n[ i ] % b;
        n[ i ] /= b;
    }
    format();
}
void BigInteger::print() const
{
    printf( "%d", n[ len - 1 ] );
    for ( int i = len - 2; i > -1; --i )
    {
        printf( "%0*d", FK, n[ i ] );
    }
    return;
}
int main()
{
    BigInteger a;
    int n,i,m = 0,b[4000];
    scanf("%d",&n);
    
    for (i=2;n>=i;i++)
    {
      b[++m] = i;
      n -= i;
    }
    while (n>0)
    {
      for (i=m;i>=1 && n>0;i--)
      {
        b[i]++;
        n--;
      }
    }
    for (i=1;i<m;i++)
     printf("%d ",b[i]);
    printf("%d\n",b[m]);
    a = 1;
    for (i=1;i<=m;i++)
     a *= b[i];
	a.print();
	cout << endl;
	cin >> n;
    return 0;
}

