var
x,y:array[1..100000] of int64 ;
k,p,n,mix:int64;
i,j:longint;
min:real;

procedure qsort(l,r: int64);
var
i,j: longint;
mid,t:int64;
begin
i:=l; j:=r; mid:=x[(l+r) div 2];
repeat
while x[i]<mid do inc(i);
while mid<x[j] do dec(j);
if not(i>j) then
begin
t:=x[i]; x[i]:=x[j]; x[j]:=t;
t:=y[i]; y[i]:=y[j]; y[j]:=t;
inc(i); dec(j);
end;
until i>j;
if l<j then qsort(l,j);
if i<r then qsort(i,r);
end;


begin
readln(n);
for i:=1 to n do
readln(x[i],y[i]);
qsort(1,n);min:=100000000000;
for i:=1 to n-1 do
begin
mix:=maxlongint;
for j:=i+1 to n do
if abs(x[j]-x[i])>min then break else if
 (sqrt((y[j]-y[i])*(y[j]-y[i])+(x[j]-x[i])*(x[j]-x[i]))<min)and
 (mix>abs(y[j]-y[i]))
 then begin
min:= sqrt(sqr(y[j]-y[i])+sqr(x[j]-x[i]));
mix:=abs(y[j]-y[i]);end;
end;
writeln(min:0:3);
end.

