program t1063;
const
	maxn = 205;
var
	f , g : array [ -1 .. maxn , -1 .. maxn ] of longint;
        //g : array [ 1 .. maxn , 1 .. maxn ] of char;
	n , ans : longint;


procedure init;
var
	i , j : longint;
	ch : char;
begin
	fillchar ( f , sizeof ( f ) , $FF );
	readln ( n );
	for i := 1 to n do begin
                read ( ch );
                while( ch = ' ' ) do read ( ch );
	     	for j := 1 to ( n - i + 1 ) shl 1 - 1 do begin
			if ( ch = '-' ) then f[ i , j ] := 1;
                        read ( ch );
		end;
		readln;
	end;
end;

function min ( a , b : longint ): longint;
begin
	if ( a < b ) then min := a
		else min := b;
end;


procedure dp;
var
	i , j , k : longint;
begin
	ans := 0;   g := f;
	for i := 2 to n do
	    for j := 1 to ( n - i + 1 ) shl 1 - 1 do
              if ( j and 1 = 1 ) then if ( f[ i , j ] > 0 ) then begin
		 if( f[ i - 1 , j ] > 0 )and( f[ i - 1 , j + 2 ] > 0 )and( f[ i - 1 , j + 1 ] > 0 ) then
			f[ i , j ] := min( f[ i - 1 , j ] , f[ i - 1 , j + 2 ] ) + 1;
		 if ( f[ i , j ] > ans ) then ans := f[ i , j ];
	    end;
	for i := n downto 1 do
	    for j := 1 to ( n - i + 1 ) shl 1 - 1 do
              if ( j and 1 = 0 ) then if ( g[ i , j ] > 0 ) then begin
		 if ( g[ i + 1 , j - 2 ] > 0 )and( g[ i + 1 , j ] > 0 )and( g[ i + 1 , j - 1 ] > 0 ) then
			g[ i , j ] := min ( g[ i + 1 , j - 2 ] , g[ i + 1 , j ] ) + 1;
			if ( g[ i , j ] > ans ) then ans := g[ i , j ];
	    end;
	writeln ( ans * ans );
end;


begin
	init;
	dp;
end.

