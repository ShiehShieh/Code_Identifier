program p1062;
var
i,j,k,l,o,n,s,h:longint;
a:array[1..100000] of integer;
b,c:array[1..2000] of integer;
begin
readln(n);
k:=1; l:=0; o:=0;
for i:=1 to n do
begin
read(b[i]);
l:=b[i]-o;
o:=b[i];
k:=k+l;
a[k]:=1;
inc(k);
end;
s:=k-1;
readln;
for i:=1 to n do
begin
for j:=1 to s do
if a[j]=1 then break;
h:=0;
for k:=j downto 1 do
begin
if a[k]=0 then break;
if a[k]=2 then inc(h);
end;
inc(h);
a[j]:=3; a[k]:=2;
write(h,' ');
end;
readln
end. 

