var a:array[0..101,1..3]of longint;
    i,j,n,max,maxn:longint;
begin
  readln(n);
  a[0,1]:=-maxlongint;
  a[n+1,1]:=-maxlongint;
  for i:=1 to n do
  begin
    read(a[i,1]);
    a[i,2]:=1;
    a[i,3]:=1;
  end;
  for i:=1 to n do
  begin
    max:=0;
    for j:=i-1 downto 0 do
      if(a[j,1]<a[i,1])and(a[j,2]>max)then max:=a[j,2];
    inc(a[i,2],max);
  end;
  for i:=n downto 1 do
  begin
    max:=0;
    for j:=i+1 to n+1 do
      if(a[j,1]<a[i,1])and(a[j,3]>max)then max:=a[j,3];
    inc(a[i,3],max);
  end;
  maxn:=0;
  for i:=1 to n do
    if a[i,2]+a[i,3]>maxn then maxn:=a[i,2]+a[i,3]-1;
  writeln(n-maxn);
end.
