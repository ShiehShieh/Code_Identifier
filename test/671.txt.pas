var n,i,x,ans:longint;
    a:array[1..1000] of longint;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    x:=x+a[i];
  end;
  ans:=0;
  x:=x div n;
  for i:=1 to n-1 do
    if a[i]<>x then
    begin
      a[i+1]:=a[i+1]+a[i]-x;
      ans:=ans+1;
    end;
  writeln(ans);
end.
