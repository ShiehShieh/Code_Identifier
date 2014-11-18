//vij1011
const
  maxn=500;
  maxh=50000;
  d:array[1..4,1..2] of integer=( (0,-1), (1,0), (0,1), (-1,0) );
var
  f,a:array[1..maxn,1..maxn] of longint;
  vis:array[1..maxn,1..maxn] of boolean;
  r,c:integer;
procedure init;
var
  i,j:integer;
begin
  readln(r,c);
  for i:=1 to r do
  begin
    for j:=1 to c do
      read(a[i,j]);
  end;
end;

function getf(i,j:integer):longint;
var
  i1,j1,k:integer;
  temp,max:longint;
begin
  if vis[i,j] then
     exit( f[i,j]);
  vis[i,j]:=true;

  max:=1;
  for k:=1 to 4 do
  begin
    i1:=i+d[k,1]; j1:=j+d[k,2];
    if (i1<1) or (i1>r) or (j1<1) or (j1>c) then
     continue;

    if (a[i1,j1]<a[i,j]) then
    begin

      temp:=getf(i1,j1);
      if temp+1>max then
        max:=temp+1;
    end;
  end;

  f[i,j]:=max;
  exit(max);
end;
procedure solve;
var
  i,j:integer;
  max,temp:longint;
begin
  fillchar(vis,sizeof(vis),false);
  max:=1;
  for i:=1 to r do
    for j:=1 to c do
    begin
      f[i,j]:=1;
    end;

  for i:=1 to r do
    for j:=1 to c do
    begin
      temp:=getf(i,j);
      if temp>max then
        max:=temp;
    end;
  writeln(max);
end;


begin
  
  init;
  solve;
end.

