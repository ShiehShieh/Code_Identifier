var
  n,i:integer;
  m:int64;

begin
  readln(n);
  m:=1;
  for i:=1 to n do
    m:=(m*(n+i)) div i;
  m:=m div (n+1);
  writeln(m);
end.

