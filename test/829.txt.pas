program p1061;
var a:array[1..5000]of integer;
    f:array[0..5000,0..1000]of longint;
    i,j,m,n:integer;
function min(a,b:longint):longint;
begin
    if a>b then exit(b) else exit(a);
end;
begin
    readln(m,n);
    for i:=1 to n do read(a[i]);
    for i:=1 to n do
     for j:=1 to m do
     f[i,j]:=9999999;
    for i:=n-2 downto 1 do
     for j:=1 to min((n-i+1) div 3,m) do
     f[i,j]:=min(f[i+1,j],f[i+2,j-1]+sqr(a[i+1]-a[i]));
    writeln(f[1,m]);
end.


