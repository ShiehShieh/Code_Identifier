var
max,min,i,j,n,m:integer;
f:array[1..1000,1..1000]of integer;
begin
readln(n,m);
max:=0;
for i:=1 to n do for j:=1 to m do read(f[i,j]);
for i:=2 to n do for j:=2 to m do if f[i,j]<>0 then
begin
min:=10000;
if f[i-1,j]<min then min:=f[i-1,j];
if f[i,j-1]<min then min:=f[i,j-1];
if f[i-1,j-1]<min then min:=f[i-1,j-1];
f[i,j]:=min+1;
if f[i,j]>max then max:=f[i,j];
end;
if max=0 then writeln(1) else writeln(max);
end.
