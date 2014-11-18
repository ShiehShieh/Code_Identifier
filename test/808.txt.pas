program P1122(input,output);
var
  n,i:integer;
  ans:int64;
begin
  readln(n);
  ans:=1;
  for i:=1 to n do
    ans:=ans*(n+i) div i;
  ans:=ans div (n+1);
  writeln(ans);
end.
