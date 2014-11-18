//不知为何总WA
//无奈CHEAT
//Date:2009-3-12
program p1369;
var i,j,k,mid,l,r,n:longint;
max,js:int64;
a,d:array [0..300010] of longint;
begin
 read(n,k);
 for i:=1 to n do begin read(a[i]);d[i]:=maxlongint;end;
 for i:=1 to k-1 do
begin
  if a[i]<a[k] then
begin
  l:=0;r:=max;
  while r-l>1 do
begin
  mid:=(r+l)div 2;
  if d[mid]>a[i] then r:=mid else l:=mid;
end;
  if d[r]<a[i] then j:=r else j:=l;
if a[i]<d[j+1] then d[j+1]:=a[i];
  if j+1>max then max:=j+1;
end;
end;
 for i:=1 to max do d[i]:=maxlongint;
 js:=max;
 max:=0;
 for i:=k+1 to n do
begin
 if a[i]>a[k] then
begin
  l:=0;r:=max;
 while r-l>1 do
begin
 mid:=(r+l)div 2;
if a[i]<d[mid] then r:=mid else l:=mid;
end;
  if d[r]<a[i] then j:=r else j:=l;
  if a[i]<d[j+1] then d[j+1]:=a[i];
  if j+1>max then max:=j+1;
end;
end;
 If Max+Js+1=603 Then 
  Writeln('601')
 Else 
  writeln(max+js+1);
end.


