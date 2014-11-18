program t1064;
const
c:array[0..9,1..5,1..3]of char   =(((' ','-',' '),('|',' ','|'),(' ',' ',' '),('|',' ','|'),(' ','-',' '))
                                   ,((' ',' ',' '),(' ',' ','|'),(' ',' ',' '),(' ',' ','|'),(' ',' ',' '))
                                   ,((' ','-',' '),(' ',' ','|'),(' ','-',' '),('|',' ',' '),(' ','-',' '))
                                   ,((' ','-',' '),(' ',' ','|'),(' ','-',' '),(' ',' ','|'),(' ','-',' '))
                                   ,((' ',' ',' '),('|',' ','|'),(' ','-',' '),(' ',' ','|'),(' ',' ',' '))
                                   ,((' ','-',' '),('|',' ',' '),(' ','-',' '),(' ',' ','|'),(' ','-',' '))
                                   ,((' ','-',' '),('|',' ',' '),(' ','-',' '),('|',' ','|'),(' ','-',' '))
                                   ,((' ','-',' '),(' ',' ','|'),(' ',' ',' '),(' ',' ','|'),(' ',' ',' '))
                                   ,((' ','-',' '),('|',' ','|'),(' ','-',' '),('|',' ','|'),(' ','-',' '))
                                   ,((' ','-',' '),('|',' ','|'),(' ','-',' '),(' ',' ','|'),(' ','-',' ')));
var
	i , j , n , size : longint;
	num : array[ 1 .. 300 ] of longint;

procedure init;
var
	i : longint;
	ch : char;
begin
	readln ( size );   n := 0;
	while not seekeoln do begin
		read ( ch );
		inc ( n );
		val ( ch , num[ n ] );
	end;
end;


procedure work;
var
	i , j , k , l , i1 , j1 , k1 : longint;
	s : ansistring;
begin
	for i := 1 to 5 do begin
            s := '';
	    if ( i and 1 = 1 ) then begin
		for j := 1 to n do begin
			for k := 1 to 3 do
                                if(  c[ num[ j ] , i , k ] = '-' )or( k = 2 ) then
					for l := 1 to size do s := s + c[ num[ j ] , i , k ]
                                else s := s + ' ';
                        if ( j < n ) then s := s + ' ' ;
		end;
                writeln ( s );
            end
	    else begin
		s := '';
		for j := 1 to n do begin
			for k := 1 to 3 do
				if ( c[ num[ j ] , i , k ] = ' ' )and( k = 2 ) then
					for l := 1 to size do s := s + ' '
				else s := s + c[ num[ j ] , i , k ];
                        if ( j < n ) then s := s + ' ';
                end;
		for j := 1 to size do writeln ( s );
	    end;
	end;
end;

begin
	init;
	work;
end.

