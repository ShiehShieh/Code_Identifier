var
i,j,k,n:longint;
a:array[1..2500,0..2] of int64;
begin
readln(n);
for i:=1 to n do
for j:=1 to n do
begin
read(k);
a[k,0]:=0;a[k,1]:=i;a[k,2]:=j;
end;
for i:=sqr(n)-1 downto 1 do
for j:=sqr(n) downto i+1 do
begin
k:=sqr(abs(a[i,1]-a[j,1])+abs(a[i,2]-a[j,2]))+a[j,0];
if k>a[i,0] then a[i,0]:=k;
end;
writeln(a[i,0]);
end.
