var  i,n,j,m,b,c,z,max:longint;
a:array[1..100,1..100] of char;
begin 
readln(n);
readln(m);
for i:=1 to n do begin
for j:=1 to n-1 do read(a[i,j]);
readln(a[i,n]);
end;
max:=0;
for b:=1 to n-m+1 do 
for c:=1 to n-m+1 do begin 
z:=0;
for i:=b to b-1+m do
for j:=c to c-1+m do 
if a[i,j]='#' then z:=z+1;
if z>max then max:=z;
end;
write(max);
end.
 
