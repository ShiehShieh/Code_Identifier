var
p,q:real;
i:longint;
begin
readln(p,q);
i:=0;
repeat
inc(i);
until trunc(i*p/100+0.00001)+1=trunc(i*q/100-0.00001);
writeln(i);
end.

