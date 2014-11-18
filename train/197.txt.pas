var
  n,i,j,max:longint;
  a:array[1..100] of 130..230;
  f,ff:array[1..100] of integer;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do f[i]:=1;
  for i:=1 to n do ff[i]:=1;
  for i:=2 to n do
    for j:=1 to i-1 do
      if (a[i]>a[j]) and (f[i]<f[j]+1) then
        f[i]:=f[j]+1;
  for i:=n-1 downto 1 do
    for j:=i+1 to n do
      if (a[j]<a[i]) and (ff[i]<ff[j]+1) then
        ff[i]:=ff[j]+1;
  max:=0;
  for i:=1 to n do
    if f[i]+ff[i]>max then
      max:=f[i]+ff[i];
  writeln(n-max+1);
end.
