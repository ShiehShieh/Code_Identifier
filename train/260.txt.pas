var
a:array[0..2600]of longint;
l,r,sum,i,n:longint;
v:boolean;
procedure jiecheng;
var
j:integer;
begin
while a[l]=0 do inc(l);
for j:=l to r do
 a[j]:=a[j]*i;
for j:=l to r do
 begin
 a[j+1]:=a[j+1]+a[j] div 10000;
 a[j]:=a[j] mod 10000;
 end;
while a[r]=0 do dec(r);
inc(r);
end;
begin
read(n);
if n=1 then begin write('1F'); halt; end;
a[1]:=1;
l:=1;
r:=1;
v:=true;
for i:=1 to n do
jiecheng;
for i:=l to r do
 sum:=sum+(a[i] mod 10000) div 1000+(a[i] mod 1000) div 100+(a[i] mod 100) div 10+(a[i] mod 10);
for i:=2 to round(sqrt(sum)) do
 if sum mod i=0 then
 begin
 v:=false;
 break;
 end;
if not v then writeln(sum,'F')
else writeln(sum,'T');
end.
