program v1007;
const p=3.14159;
var
n,i:integer;
r:real;l:extended;
a,b:array[1..101]of real;
begin
readln(n,r);
for i:=1 to n do readln(a[i],b[i]);
for i:=1 to n-1 do
l:=l+sqrt(sqr(a[i+1]-a[i])+sqr(b[i+1]-b[i]));
l:=l+sqrt(sqr(a[n]-a[1])+sqr(b[n]-b[1]));
l:=l+2*p*r;
writeln(l:0:2);
end.
