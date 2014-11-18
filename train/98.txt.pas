program zuiduanlushangdetongji;
var  f:array[0..100,0..100] of integer;
i,j,k,l,n,m,a,b,p:integer;

begin
readln(n,m);
for i:=1 to n do
  for j:=1 to n do
   f[i,j]:=9999;
for i:=1 to m do
 begin
 read(a,b);
 f[a,b]:=1;
 f[b,a]:=1;
 end;
for k:=1 to n do
  for i:=1 to n do
    for j:=1 to n do
    if f[i,j]>f[i,k]+f[k,j] then
      f[i,j]:=f[i,k]+f[k,j];
readln(p);
for i:=1 to p do
begin
 readln(a,b);
 m:=0;
 for j:=1 to n do
 if f[a,j]+f[j,b]=f[a,b] then inc(m);
 writeln(m+2);
end;
end.

