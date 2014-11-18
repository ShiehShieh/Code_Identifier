var
n,m,r,t:real;
begin
readln(m,n,r);
if m-n>0 then
begin
t:=sqrt((m-n)*(m-n)+r*r);
writeln(t:0:3);
end
else
writeln(r:0:3);
end.
