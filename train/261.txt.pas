var f:array[0..100,0..2000]of integer;
n,m,i,j,k:integer;
a:array[1..100]of integer;
function max(x,y,z:integer):integer;
begin
max:=x;
if max<y then max:=y;
if max<z then max:=z;
end;
begin
readln(n);m:=0;
for i:=1 to n do
begin
read(a[i]);
m:=m+a[i];
end;
for i:=0 to n do
for j:=0 to m do
f[i,j]:=-1000;
f[0,0]:=0;
for i:=1 to n do
for j:=0 to m  do
begin
if a[i]<j then
f[i,j]:=max(f[i-1,j],f[i-1,j+a[i]],f[i-1,j-a[i]]+a[i])
else
f[i,j]:=max(f[i-1,j],f[i-1,j+a[i]],f[i-1,a[i]-j]+j);
end;
if f[n,0]>0 then
write(f[n,0])
else
write('Impossible');
end.
