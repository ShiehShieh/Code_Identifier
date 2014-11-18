var
total,m,n,x,k,p,i,j:longint;
a:array[0..10000]of longint;
begin
 p:=0;
 total:=0;
 readln(m,n);
 for x:=0 to m do a[x]:=1;
 repeat
  p:=p+1;
  readln(i,j);
  for k:=i to j do a[k]:=0;
  until p=n;
  for x:=0 to m do
  if a[x]=1 then total:=total+1;
  writeln(total);
end.
