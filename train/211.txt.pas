program temp;
var
f:array[1..500]of longint;
n,x,y,l,i:integer;

procedure cheng(k:longint);
var
i,j:integer;
begin
for i:=1 to l do f[i]:=f[i]*k;
for i:=2 to l+1 do
 begin
f[i]:=f[i]+f[i-1] div 10000;
f[i-1]:=f[i-1] mod 10000;
 end;
while f[l+1]>0 do inc(l);
end;

begin
read(n);
if n=0 then begin write('0'); halt; end;
if n=1 then begin write('1'); halt; end;
if n=2 then begin write('2'); halt; end;
x:=n div 3;
y:=n mod 3;
fillchar(f,sizeof(f),0);
f[1]:=1;
l:=1;
if y=0 then for i:=1 to x do cheng(3);
if y=1 then
 begin
for i:=1 to x-1 do cheng(3);
for i:=1 to 2 do cheng(2);
 end;
if y=2 then
 begin
for i:=1 to x do cheng(3);
cheng(2);
 end;
write(f[l]);
for i:=l-1 downto 1 do
 write(f[i] div 1000,(f[i] div 100) mod 10,(f[i] div 10) mod 10, f[i] mod 10);
end.

