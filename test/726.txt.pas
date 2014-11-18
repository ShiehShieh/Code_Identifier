program P1319(input,output);
var
  k,n:integer;
  ans,t:longint;
begin
  readln(k,n);
  ans:=0; t:=1;
  while n<>0 do
    begin
      ans:=ans+(n mod 2)*t;
      n:=n div 2;
      t:=t*k;
    end;
  writeln(ans);
end.
