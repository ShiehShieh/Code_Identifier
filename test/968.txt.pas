program p1139;
type node=record
            x,y:integer;
          end;
var m,n:integer;
    a,f:array [1..100,1..500] of longint;
    g:array [1..100,1..500] of node;
procedure init;
var i,j:integer;
begin
  readln(m,n);
  for i:=1 to m do
    for j:=1 to n do
      read(a[i,j]);
  for i:=1 to m div 2 do
  begin
    f[i]:=a[i];
    a[i]:=a[m-i+1];
    a[m-i+1]:=f[i];
  end;
end;
procedure pt(xx:integer);
var i,j:integer;
begin
  for j:=1 to 20 do
  begin
  for i:=n-1 downto 1 do
    if f[xx,i+1]+a[xx,i]<f[xx,i] then
    begin
      f[xx,i]:=a[xx,i]+f[xx,i+1];
      g[xx,i].x:=xx;
      g[xx,i].y:=i+1;
    end;
  for i:=2 to n do
    if f[xx,i-1]+a[xx,i]<f[xx,i] then
    begin
      f[xx,i]:=a[xx,i]+f[xx,i-1];
      g[xx,i].x:=xx;
      g[xx,i].y:=i-1;
    end;
  end;
end;
procedure digit(p,q:integer);
begin
  if (g[p,q].x<>0) and (g[p,q].y<>0) then digit(g[p,q].x,g[p,q].y);
  writeln(q);
end;
function main:integer;
var i,j,p,q:longint;
begin
  fillchar(f,sizeof(f),0);
  fillchar(g,sizeof(g),0);
  f[m]:=a[m];
  for i:=m-1 downto 1 do
  begin
    for j:=1 to n do
    begin
      f[i,j]:=f[i+1,j]+a[i,j];
      g[i,j].x:=i+1;
      g[i,j].y:=j;
    end;
    pt(i);
  end;
  j:=maxlongint;
  for i:=1 to n do
    if f[1,i]<j then
    begin
      j:=f[1,i];
      q:=i;
    end;
  main:=q;
end;
begin
  init;
  digit(1,main);
end.
