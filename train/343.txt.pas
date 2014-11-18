var
  a:array[1..100,1..200]of char;
  f:array[0..102,0..205]of integer;
  v:array[0..102,0..205]of boolean;
  n,i,j,max:integer;
 
function min(aa,bb:integer):integer;
begin if aa<bb then exit(aa) else exit(bb);end;
 
procedure up(x,y:integer);
begin
  if v[x,y] then exit;
  v[x,y]:=true;
  if x=1 then
  begin f[x,y]:=ord(a[x,y]='-');exit;end;
  up(x-1,y-1);up(x-1,y+1);
  if a[x,y]='#' then f[x,y]:=0 else
  if a[x-1,y]='#' then f[x,y]:=1 else
  f[x,y]:=min(f[x-1,y-1],f[x-1,y+1])+1;
end;
 
procedure down(x,y:integer);
begin
  if v[x,y] then exit;
  v[x,y]:=true;
  if (y<x) or (y>n+n-x) then exit;
  if x=n-1 then
  begin f[x,y]:=ord(a[x,y]='-');exit;end;
  down(x+1,y-1);down(x+1,y+1);
  if a[x,y]='#' then f[x,y]:=0 else
  if a[x+1,y]='#' then f[x,y]:=1 else
  f[x,y]:=min(f[x+1,y-1],f[x+1,y+1])+1;
end;
 
begin
  readln(n);
  for i:=1 to n do
  begin
    for j:=1 to n+n-i do read(a[i,j]);readln;
  end;
 
  up(n,n);
  for i:=1 to n-1 do down(1,2*i);
 
  for i:=1 to n do for j:=i to n+n-i do if f[i,j]>max then max:=f[i,j];
  writeln(sqr(max));
end.
