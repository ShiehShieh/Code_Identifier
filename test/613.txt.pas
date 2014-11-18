program p1423;
var
  i,j,n,m,k,a,b,c,min,minn:longint;
  f,time:array[1..200] of longint;
  g:array[1..200,1..200] of longint;
  visited:array[1..200] of boolean;
begin
  readln(n,m);
  for i:=1 to n do
    for j:=1 to n do
      g[i,j]:=maxlongint;
  for i:=1 to n do readln(time[i]);
  for i:=1 to m do
  begin
    readln(a,b,c);
    if c<g[a,b] then
    g[a,b]:=c;
  end;
  for i:=2 to n do
    if g[1,i]<>maxlongint then f[i]:=g[1,i]+time[i]
    else
      f[i]:=maxlongint;
  for k:=1 to n-2 do
  begin
    min:=maxlongint;
    for i:=2 to n do if (f[i]<min) and (visited[i]=false) then
    begin
      min:=f[i];
      minn:=i;
    end;
    visited[minn]:=true;
    for i:=2 to n do
      if (g[minn,i]<>maxlongint) and (visited[i]=false) then
        if (f[minn]+g[minn,i]+time[i]<f[i]) then
          f[i]:=f[minn]+g[minn,i]+time[i];
  end;
  min:=maxlongint;
  for i:=2 to n do
    if (g[i,1]<>maxlongint) and (g[i,1]+f[i]+time[1]<min) then
      min:=g[i,1]+f[i]+time[1];
  if min=maxlongint then writeln(-1)
  else writeln(min);
end.
