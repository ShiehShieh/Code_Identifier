var n,t,s,i,j:longint;
    a:array[1..2500,1..3]of int64;
begin
readln(n);
for i:=1 to n do
 for j:=1 to n do
 begin
  read(t);
  a[t,1]:=i;a[t,2]:=j;
 end;
for i:=n*n+1 downto 1 do
 for j:=n*n downto i+1 do
 begin
  s:=sqr(abs(a[i,1]-a[j,1])+abs(a[i,2]-a[j,2]))+a[j,3];
  if a[i,3]<s then a[i,3]:=s;
 end;
writeln(a[1,3]);
end.
                                 
