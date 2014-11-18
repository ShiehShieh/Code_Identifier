program river;
var l,s,t,m,a,b,c,g,h:longint;
x,y:array[0..100000] of longint;
p:array[1..1000000000] of boolean;
procedure init;
begin
  readln(l);
  readln(s,t,m);
  for a:=1 to m do
  begin
  read(y[a]);
  end;
end;
procedure qsort(l,r:longint);
var i,j,mid,n:longint;
begin
  i:=l;
  j:=r;
  mid:=y[(i+j) div 2];
  repeat
  while (i<=j) and (y[i]<mid) do inc(i);
  while (i<=j) and (y[j]>mid) do dec(j);
  if i<=j then
  begin
 n:=y[i];
 y[i]:=y[j];
 y[j]:=n;
 inc(i);
 dec(j);
  end;
  until i>j;
  if i<r then qsort(i,r);
  if j>l then qsort(l,j);
end;
procedure press;
var a,b:longint;
c:array[0..100] of longint;
begin
  c[0]:=0;
  for a:=0 to m-1 do
  begin
    if (y[a]+100<y[a+1]) then
  begin
  c[a+1]:=c[a]+y[a+1]-y[a]-100;
  end
  else c[a+1]:=c[a];
  end;
  for a:=1 to m do y[a]:=y[a]-c[a];
end;
procedure jump;
var a,b,c,d,k:longint;
begin
  for a:=1 to l do
  begin
  x[a]:=maxint;
  if p[a] then k:=1
 else k:=0;
  for b:=s to t do
  begin
if (a-b>=0) then
begin
  if x[a-b]<x[a] then x[a]:=x[a-b];
end;
  end;
  x[a]:=x[a]+k;
  end;
end;
begin
  init;
  fillchar(x,sizeof(x),$ff);
  x[0]:=0;
  qsort(1,m);
  if s<>t then
  begin
  press;
  l:=y[m]+100;
  for a:=1 to m do
  begin
  p[y[a]]:=true;
  end;
  jump;
  writeln(x[l]);
  end
  else
  begin
  for a:=1 to m do
  if (y[a] mod s=0) then inc(g);
  writeln(g);
  end;
end.

