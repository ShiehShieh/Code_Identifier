var m,n,m1,m2,s:integer;
begin
 readln(m,n);
 m1:=m div n;
 m2:=m mod n;
 if odd(n) then
begin
if m2<=n div 2 then
s:=m1*(n div 2)+m2+1
else
s:=m1*(n div 2)+n div 2+1;
end
 else
begin
if m2<=n div 2 then
s:=m1*(n div 2-1)+m2+2
else
s:=m1*(n div 2-1)+n div 2+1;
end;
 writeln(s);
end.

