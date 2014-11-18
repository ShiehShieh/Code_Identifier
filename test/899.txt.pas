var   a,b,p,q:real;
     t:longint;
begin
read(p,q);
t:=trunc(100/q);
repeat
inc(t);
a:=t*p/100;
b:=t*q/100;
until (trunc(b)-trunc(a)=1)and(b-trunc(b)>=0.00000000000000000000000001);
write(t);
end.

