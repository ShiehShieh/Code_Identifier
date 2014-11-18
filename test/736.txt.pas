var f:array [0..401,0..401] of integer;
    i,j,k,n,maxt,maxm,sum:integer;
    t,m,v:array [1..51] of integer;
begin
  read(maxt);read(maxm);
  read(n);
  for i:=1 to n do
  begin
    read(t[i]);
    read(m[i]);
    read(v[i]);
  end;
  for i:=1 to n do
    for j:=maxt downto t[i] do
      for k:=maxm downto m[i] do
      begin
        sum:=f[j-t[i],k-m[i]]+v[i];
        if sum>f[j,k] then f[j,k]:=sum;
      end;
  writeln(f[maxt,maxm]);
end.
