program p1333;
 var i,j,n:longint;
begin
 readln(n);
 i:=1;
 while n>i do
  begin
   dec(n,i);
   inc(i);
  end;
 if not odd(i) then
  writeln(n,'/',i+1-n)
 else 
  writeln(i+1-n,'/',n);
end.
 
