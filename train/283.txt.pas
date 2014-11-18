type mat=array[1..10,1..10] of qword;
var x,y:mat;
k,n,i,j:longint;
a:array[0..10] of qword;
p:qword;
procedure cf(var a,b:mat);
var c:mat;
i,j,l:longint;
begin
fillchar(c,sizeof(c),0);
for i:=1 to k do
for j:=1 to k do
for l:=1 to k do
begin
inc(c[i,j],(a[i,l] mod 7777777)*(b[l,j] mod 7777777));
c[i,j]:=c[i,j] mod 7777777;
end;
a:=c;
end;
begin
readln(k,n);
for i:=1 to k-1 do x[i,i+1]:=1;
for i:=1 to k do x[k,i]:=1;
a[1]:=1;a[2]:=1;for i:=3 to k do a[i]:=a[i-1]*2;
if n and 1=1 then y:=x else begin for i:=1 to k do y[i,i]:=1;end;
n := n shr 1;
while n>0 do
begin
cf(x,x);
if n and 1=1 then cf(y,x);
n := n shr 1;
end;
for i:=1 to k do
begin
inc(p,y[1,i]*a[i]);
p:=p mod 7777777;
end;
writeln(p);
end.
