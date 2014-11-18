program lx;
var
  i,n:longint;
  x:int64;
begin
  x:=0;
  readln(n);
  for i:=1 to n do
  x:=x+i*i;
  writeln(x);
end.
