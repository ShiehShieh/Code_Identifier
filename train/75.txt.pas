program zuiduanluxian;
var
f:array[0..200,0..200] of longint;
n,m,i,j,k,l,xi,yi,bi,p,max:longint;
v:array[0..200] of boolean;
t:array[0..200] of integer;
begin
readln(n,m);
for i:=1 to n do
read(t[i]);
for i:=1 to n do
  for j:=1 to n do
  f[i,j]:=999999999;
for i:=1 to m do
begin
readln(xi,yi,bi);
if bi+t[xi]<f[xi,yi] then f[xi,yi]:=bi+t[xi];
end;
for j:=2 to n do
 begin
 max:=999999999;
 for i:=2 to n do
 if (not(v[i])) and (f[1,i]<>999999999) and (f[1,i]<max)
   then
   begin
   max:=f[1,i];
   p:=i;
   end;
v[p]:=true;
for i:=1 to n do
  if (not v[i]) and (f[p,i]<>999999999)
    then  if (f[1,i]>f[p,i]+f[1,p]) or (f[1,p]=999999999)
      then  f[1,i]:=f[p,i]+f[1,p];
  end;
if (f[1,1]=999999999) then writeln('-1') else writeln(f[1,1]);
end.
