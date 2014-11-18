var a:array[1..12]of integer;
y,s,i,x:integer;
begin
for i:=1 to 12 do readln(a[i]);
s:=0;y:=0;i:=0;
while (y>=0) and (i<>12) do
begin
inc(i);
y:=300+y-a[i];
if y<0 then
 begin
 writeln(-i);
 exit;
 end;
s:=s+y div 100;
y:=y mod 100;
end;
writeln(s*120+y);
end.
