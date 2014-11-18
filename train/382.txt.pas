program duixing;
var a:array[0..100] of integer;
    f:array[0..2,0..100] of integer;
    n,i,j,max:integer;
begin
  readln(n);
  for i:=1 to n do
    read(a[i]);
  readln;
  f[1,1]:=1; f[2,n]:=1;
  for i:=2 to n do
  begin
    max:=0;
    for j:=1 to i-1 do
      if (a[i]>a[j]) and (f[1,j]>max) then
      max:=f[1,j];
    f[1,i]:=max+1;
    max:=0;
    for j:=n downto n-i+2 do
      if (a[n-i+1]>a[j]) and (f[2,j]>max) then
      max:=f[2,j];
    f[2,n-i+1]:=max+1;
  end;
  max:=0;
  for i:=1 to n do
  begin
    if f[1,i]+f[2,i]>max then
    max:=f[1,i]+f[2,i];
  end;
  write(n-max+1);
end.
