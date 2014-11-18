program q1;
var m,n,i,j:integer;
    a:array[1..10]of integer;
begin
 for i:=1 to 10 do
  read(a[i]);
readln;
 readln(m);
 for i:=1 to 10 do
 if a[i]<=(m+30) then inc(n);
write(n);
end.
    
