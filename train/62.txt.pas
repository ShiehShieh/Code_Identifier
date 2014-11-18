var i,j,n,total:integer;
a:array[1..200,1..200] of integer;
b:array[1..200] of integer;
d:array[1..200]of boolean;
procedure dfs(k:integer);
var i,j:integer;
begin
for i:=1 to b[k] do begin
if d[a[k,i]] then
begin
d[a[k,i]]:=false;
dfs(a[k,i]);
end;
end;
end;
begin
readln(n);
total:=0;
for i:=1 to n do begin
j:=1;
read(a[i,j]);
while a[i,j]<>0 do
begin
inc(j);
read(a[i,j]);
end;
b[i]:=j-1;
readln;
end;
fillchar(d,sizeof(d),true);
for i:=1 to n do
begin
if d[i] then begin
d[i]:=false;
dfs(i);
inc(total);
end;
end;
writeln(total);
end.
