var
 n,i,a,b:integer;
 k1,k2:qword;
begin
 readln(n,a,b);
 k1:=1; k2:=1;
 for i:=1 to a do
  k1:=k1*(n+i) div i;
 for i:=1 to b do
  k2:=k2*(n+i) div i;
 writeln(k1*k2);
end.
