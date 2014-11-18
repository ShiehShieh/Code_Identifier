program yiyuansancifancheng;
var a,b,c,d,x,s:real;
i:integer;
function f(x:real):real;
begin
f:=a*x*x*x+b*x*x+c*x+d;
end;
begin
readln(a,b,c,d);
x:=-100;
for i:=1 to 3 do
begin
repeat
s:=f(x);
if abs(s)<0.001  then write(x:0:2,' ');
x:=x+0.01;
until abs(s)<0.001;
x:=x+1-0.01;
end;
end.



