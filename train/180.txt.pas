program t1061;
const
	maxn = 5005;
	maxm = 1005;
var
	f : array [ 0 .. maxm , 0 .. maxn ] of longint;
	n , m : longint;
	h , w : array [ 1 .. maxn ] of longint;


procedure init;
var
	i : longint;
begin
	read ( m , n );
	for i := 1 to n do read ( h[ n - i + 1 ] );
	for i := 2 to n do w[ i ] := ( h[ i ] - h[ i - 1 ] )*( h[ i ] - h[ i - 1 ] );
end;

procedure dp;
var
	i , j , k : longint;
begin
	fillchar ( f , sizeof ( f ) , $7f );
	for i := 0 to n do f[ 0 , i ] := 0;
	for i := 1 to m do
	      for j := i*3 to n do begin
		     f[ i , j ] := f[ i , j - 1 ];
		     if ( f[ i - 1 , j - 2 ] + w[ j ] < f[ i , j ] ) then
			   f[ i , j ] := f[ i - 1 , j - 2 ] + w[ j ];
	      end;
	writeln ( f[ m , n ] );
end;


begin
	init;
	dp;
end.
