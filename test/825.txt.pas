var
ans,x,y,z,p,k:longint;
i:integer;
begin
readln(x,y);
if(y mod x<>0)then
begin
writeln(0);
exit;
end;
z := y div x;
p:=2;
k:=0;
while(z>1) do
begin
if(z mod p=0) then
begin
inc(k);
while(z mod p=0) do z:=z div p;
end;
inc(p);
end;
ans:=1;
for i:=1 to k do
ans:=ans*2;
writeln(ans);
end.

