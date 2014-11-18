var
  a:array[0..10000,1..3] of longint;
  b,c,d,e,f,i,j,k,l,n,m,p,q,ans:longint;
procedure sqo(zuo,you:longint);
var
  i,j,x:longint;
begin
  i:=zuo;
  j:=you;
  x:=a[(i+j) div 2,k];
  while i<j do
  begin
    while a[i,k]<x do inc(i);
    while a[j,k]>x do dec(j);
    if i<=j then
    begin
      a[0]:=a[i];
      a[i]:=a[j];
      a[j]:=a[0];
      inc(i);
      dec(j);
    end;
  end;
  if i<you then sqo(i,you);
  if j>zuo then sqo(zuo,j);
end;
procedure doit;
begin
  ans:=0;
  k:=2;
  sqo(1,n);
  l:=(n+1) div 2;
  for i:=1 to n do
    ans:=ans+abs(a[i,k]-a[l,k]);
  k:=1;
  sqo(1,n);
  for i:=1 to n do
    a[i,3]:=a[i,1]-i+1;
  k:=3;
  sqo(1,n);
  e:=a[l,3];
  k:=1;
  sqo(1,n);
  for i:=1 to n do
    ans:=ans+abs(a[i,1]-(e+i-1));
end;

begin
  read(n);
  for i:=1 to n do
    read(a[i,1],a[i,2]);
  doit;
  writeln(ans);
end.
