program P1380;
var
c:array [1..1000] of integer;
j,i,a,b,s,t:longint;
begin
readln(a,b);
for i:=1 to a do read(c[i]);
for i:=1 to a-1 do
for j:=i+1 to a do
if (i*c[i]=j*c[j]) then t:=(i+j)div 2;
j:=t;s:=0;
if b=0 then for i:=1 to j do s:=s+c[i];
if b=1 then for i:=a downto j do s:=s+c[i];
writeln(j,' ',s);
end.
