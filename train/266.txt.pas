var
  n:longint;
  i,j,k:longint;
  f:array[1..200,1..200] of longint;
  a:array[1..200] of longint;
  max:longint;
begin
  readln(n);
  for i:=1 to n do
    read(a[i]);
  for i:=n+1 to 2*n+1 do
    a[i]:=a[i-n];
  for j:=3 to 2*n do
    for i:=j-2 downto 1 do
      for k:=i+1 to j-1 do
        if f[i,k]+f[k,j]+a[i]*a[k]*a[j]>f[i,j] then
          f[i,j]:=f[i,k]+f[k,j]+a[i]*a[k]*a[j];
  max:=0;
  for i:=1 to n do
    if f[i,i+n]>max then
      max:=f[i,i+n];
  writeln(max);
end.

