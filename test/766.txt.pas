var
i,j,s,m,n:integer;  
k,x1,y1,r,c,x,y:real;
a:array[1..100,1..2]of real;
begin
read(n); 
read(r);
for i:=1 to n do
for j:=1 to 2 do
read(a[i,j]);
for i:=1 to n-1 do begin
c:=c+sqrt(sqr(a[i,1]-a[i+1,1])+sqr(a[i,2]-a[i+1,2]));
end;
x1:=sqrt(sqr(a[n,1]-a[1,1])+sqr(a[n,2]-a[1,2]));
k:=2*r*3.14159;
c:=c+k+x1;
writeln(c:0:2);
end.
