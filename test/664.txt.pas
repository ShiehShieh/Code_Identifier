var
  a,b,i,j,k:integer;
  c:array[1..101,1..2]of integer;
  d:array[0..10000] of integer;
begin
  readln(a,b);
  for i:=0 to a do d[i]:=1;
  for i:=1 to b do
  begin
    readln(c[i,1],c[i,2]);
    for j:=c[i,1] to c[i,2] do
    d[j]:=0;
  end;
  k:=0;
  for i:=0 to a do
    if d[i]=1 then k:=k+1;
  writeln(k);
end. 
