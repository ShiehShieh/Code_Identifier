program tt;
var n,w,up,u,s,t:integer;
ch:char;
a,b:array[1..50]of integer;
procedure print;
var k:integer;
begin
inc(up);
for k:=1 to w do
begin
ch:=chr(b[k]+s-1+96);
write(ch);
end;
if up=5 then halt else writeln;
end;


procedure slak(p,wei:integer; so:boolean);
var i:integer;
begin
if wei=w then
begin
for i:=p to n do
if so then
begin
if i>a[wei] then begin b[wei]:=i; print; end;
end
else begin b[wei]:=i; print; end;
exit;
end;

i:=p;
while i<=n-w+wei do
begin
if so and (i<=a[wei]) then begin
i:=a[wei];
b[wei]:=i;
slak(i+1,wei+1,so);
end
else begin b[wei]:=i; slak(i+1,wei+1,false); end;
inc(i);
end;
end;



begin
readln(s,t,w);
n:=t-s+1;
up:=0;
for u:=1 to w do
begin
read(ch);
a[u]:=ord(ch)-96-s+1;
end;
slak(a[1],1,true);
end.
