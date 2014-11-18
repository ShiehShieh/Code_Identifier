Var
n,i,j,k:longint;
r,totle,fin:real;
x,y,c:array[1..100] of real;
s:string;
Const
pi=3.1415926;
Begin
totle:=0;
readln(n,r);
for i:=1 to n do readln(x[i],y[i]);
for i:=1 to n do
begin
    if i<>n then totle:=totle+sqrt(sqr(x[i]-x[i+1])+sqr(y[i]-y[i+1]))
    else totle:=totle+sqrt(sqr(x[i]-x[1])+sqr(y[i]-y[1]));
end;
fin:=totle+2*r*pi;
write(fin:0:2);
End.

