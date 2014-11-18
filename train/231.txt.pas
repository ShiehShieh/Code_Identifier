var f:array[0..100,0..2000]of longint;
a:array[1..100]of longint;
n,i,j,k,sum:longint;
begin
readln(n);
sum:=0;
for i:=1 to n do begin
read(a[i]);sum:=sum+a[i];
end;
for i:=0 to n do
for j:=1 to sum do f[i,j]:=-maxlongint;
f[0,0]:=0;
for i:=1 to n do
for j:=sum downto 0 do begin
  if f[i,j]<f[i-1,j] then f[i,j]:=f[i-1,j];
  if f[i,j]<f[i-1,j+a[i]] then f[i,j]:=f[i-1,j+a[i]];
  if (j>=a[i])and(f[i,j]<f[i-1,j-a[i]]+a[i]) then
  f[i,j]:=f[i-1,j-a[i]]+a[i];
  if (j<a[i])and(f[i,j]<f[i-1,a[i]-j]+j) then
  f[i,j]:=f[i-1,a[i]-j]+j;
end;
if f[n,0]=0 then writeln('Impossible')
else writeln(f[n,0]);
end.

