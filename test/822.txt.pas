var
n,tot:longint;
x,y:integer;
begin
read(n);
tot:=0;x:=1;y:=1;
repeat
tot:=tot+x;
inc(x);
until tot>=n;
dec(x);

tot:=tot-x;
y:=n-tot;
if x mod 2 =0
then write(y,'/',x-y+1)
else write(x-y+1,'/',y);
end.

