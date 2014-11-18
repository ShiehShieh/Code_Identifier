var
  i,n:longint;
  a:array[1..30]of longint;
  v:array[1..30,1..30]of longint;
  t:array[1..30,1..30]of longint;
function dfs(x,y:longint):longint;
var
  i:longint;
begin
  dfs:=0;
  if x>y then
    begin
      dfs:=1;
      exit;
    end;
  if x=y then
    begin
      dfs:=a[x];
      t[x][y]:=x;
      exit;
    end;
  if v[x][y]>0 then
    begin
      dfs:=v[x][y];
      exit;
    end;
  for i:=x to y do
    if dfs<dfs(x,i-1)*dfs(i+1,y)+a[i] then
      begin
        dfs:=dfs(x,i-1)*dfs(i+1,y)+a[i];
        t[x][y]:=i;
      end;
  v[x][y]:=dfs;
end;
procedure print(x,y:longint);
begin
  if x>y then exit;
  write(t[x][y],' ');
  if x<y then
    begin
      print(x,t[x][y]-1);
      print(t[x][y]+1,y);
    end;
end;
begin
  fillchar(v,sizeof(v),0);
  fillchar(t,sizeof(t),0);
  readln(n);
  for i:=1 to n do read(a[i]);
  writeln(dfs(1,n));
  print(1,n);
end.
