{
ID:shadow_3
PROG:p1133
LANG:PASCAL
}

const
	maxv=50000;

var
	i,p,n,j:longint;
	a:array[0..50]of longint;
	f:array[0..maxv]of boolean;

begin


	readln(p);
	readln(n);
	for i:=1 to n do readln(a[i]);
	f[1]:=true;
	for i:=1 to n do
		for j:=p-a[i] downto 1 do if f[j] then f[j+a[i]]:=true;
	for i:=p downto 0 do if f[i] then break;
	writeln(p-i+1);


end.
