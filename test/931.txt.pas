var n,i,j,k,l:integer;
    p:array[1..30]of integer;
    f:array[0..31,0..31]of cardinal;
    root:array[1..30,1..30]of integer;
    s:array[1..30]of integer;
procedure dfs(i,j:integer);
begin
  if k=n then exit;
  inc(k);
  s[k]:=root[i,j];
  if root[i,j]-1>=i then dfs(i,root[i,j]-1);
  if root[i,j]+1<=j then dfs(root[i,j]+1,j);
end;
begin
  readln(n);
  for i:=1 to n do
    read(p[i]);
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
  begin
    f[0,i]:=1;
    f[i,0]:=1;
    f[n+1,i]:=1;
    f[i,n+1]:=1;
  end;
  for i:=1 to n do
  begin
    f[i,i]:=p[i];
    root[i,i]:=i;
  end;
  for i:=1 to n-1 do
  begin
    f[i,i+1]:=p[i]+p[i+1];
    root[i,i+1]:=i;
  end;
  for l:=3 to n do
    for i:=1 to n do
    begin
      j:=i+l-1;
      if j<=n then
        for k:=i to j do
          if f[i,j]<=f[i,k-1]*f[k+1,j]+p[k] then
          begin
            f[i,j]:=f[i,k-1]*f[k+1,j]+p[k];
            root[i,j]:=k;
          end;
    end;
  writeln(f[1,n]);
  k:=0;
  dfs(1,n);
  for i:=1 to n-1 do
    write(s[i],' ');
  write(s[n]);
end. 
