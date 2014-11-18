var a:array [1..10] of integer;  i,t,b:integer;
begin
  for i:=1 to 9 do read(a[i]);readln(a[10]);
  read(b);
  for i:=1 to 10 do if a[i]<=(b+30)then t:=t+1;
  write(t);
  writeln;
  end.

