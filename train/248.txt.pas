{
ID:shadow_3
PROG:p1077
LANG:PASCAL
}

type
	matrix=array[1..4,1..4]of longint;

var
	i,j,n:longint;
	f,mt:matrix;

operator *(a,b:matrix)c:matrix;
var
	i,j,k:longint;
begin
	fillchar(c,sizeof(c),0);
	for i:=1 to 4 do
		for j:=1 to 4 do
			for k:=1 to 4 do inc(c[i,j],a[i,k]*b[k,j]);
	for i:=1 to 4 do
		for j:=1 to 4 do c[i,j]:=c[i,j] mod 100;
end;

function exp(b:matrix;p:longint):matrix;
var
	t:matrix;
begin
	if p=1 then exit(b);
	t:=exp(b,p div 2);
	t:=t*t;
	if odd(p) then t:=t*b;
	exp:=t;
end;

begin



	for i:=1 to 4 do
		for j:=1 to 4 do mt[i,j]:=1;
	for i:=1 to 4 do mt[i,i]:=2;
	for i:=1 to 4 do mt[i,4-i+1]:=0;

	repeat
		readln(n);
		if n=0 then break;
		if n=1 then
		begin
			writeln(2);
			continue;
		end;
		if n=2 then
		begin
			writeln(6);
			continue;
		end;
		fillchar(f,sizeof(f),0);
		f[1,1]:=1;
                f:=f*exp(mt,n);
		if f[1,1]<10 then write(0);
		writeln(f[1,1]);
	until false;



end.

