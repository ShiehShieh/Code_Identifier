program temp;
 
var
n,m,i,j,max:longint;
begin
for i:=1 to 10 do
begin
 readln(n,m);
 if n>m then
 if n mod 4=0 then writeln(2) else writeln(1)
 else if m mod 4=0 then writeln(1) else writeln(2);
end;
end.
