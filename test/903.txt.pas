program vijos_P1014;
const
  maxn=1000;
  maxmax=1e38;
type
  xy=record x,y:real; end;
var
  n:longint;
  a:array[1..maxn] of xy;
  d:array[1..maxn,1..maxn] of real;
  g:array[1..maxn,1..maxn] of real;
  tmp:xy;

procedure qsort(s,t:longint);
var i,j:longint;
    xx:real;
begin
  i:=s; j:=t; xx:=a[(i+j)>>1].x;
  repeat
    while a[i].x<xx do inc(i);
    while a[j].x>xx do dec(j);
    if i<=j then begin
      tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      inc(i); dec(j);
    end;
  until i>j;
  if s<j then qsort(s,j);
  if i<t then qsort(i,t);
end;

function get(a,b:real):real;
begin exit(sqrt(a*a+b*b)) end;

procedure ini;
var i,j:longint;
begin
  readln(n);
  for i:=1 to n do readln(a[i].x,a[i].y);
  qsort(1,n);
  for i:=1 to n do for j:=1 to n do
    g[i,j]:=get(a[i].x-a[j].x,a[i].y-a[j].y);
end;

procedure solve;
var i,j:longint;
    min,tmp:real;
begin
  for i:=1 to n do for j:=1 to n do d[i,j]:=maxmax;
  d[1,2]:=g[1,n]+g[1,2]+g[2,n];
  for i:=1 to n-1 do
    for j:=i+1 to n-1 do begin
      tmp:=d[i,j]-g[i,n]+g[i,j+1]+g[j+1,n];
      if tmp<d[j,j+1] then d[j,j+1]:=tmp;
      tmp:=d[i,j]-g[j,n]+g[j,j+1]+g[j+1,n];
      if tmp<d[i,j+1] then d[i,j+1]:=tmp;
    end;
{  for i:=2 to n-1 do begin
    for j:= i-1 downto 1 do begin
      tmp:=d[j]-g[j,n]+g[j,i]+g[i,n];
      if tmp<min then min:=tmp;
    end;
    d[i]:=tmp;
  end;
}
end;

procedure print;
var i:longint;
    min:real;
begin
  min:=maxmax;
  for i:=1 to n-2 do
    if d[i,n-1]<min then
      min:=d[i,n-1];
  writeln(min:0:2);
end;

begin
  ini;
  solve;
  print;
end.

