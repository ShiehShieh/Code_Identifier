var
a,b,c,m,n:qword;i:longint;
begin
for i:=1 to 10 do
begin
readln(a,b);m:=a;n:=b;
c:=a mod b;
while c<>0 do
begin
a:=b;b:=c;c:=a mod b;
end;
writeln(m+n-b);
end;
end.
