program P1028;
var i,j,n,m,k,s:integer;
    a:array[1..2000]of string;
    b:array[1..2000]of integer;
begin
 readln(n);
 for i:=1 to n do
  begin
   b[i]:=1;
   readln(a[i]);
  end;
 for i:=2 to n do
  for j:=1 to i-1 do
   if length(a[j])<length(a[i]) then
    begin
     s:=0;
     for k:=1 to length(a[j]) do
      if a[i][k]<>a[j][k] then s:=1;
     if s=0 then if b[j]+1>b[i] then b[i]:=b[j]+1;
    end;
 m:=0;
 for i:=1 to n do
  if b[i]>m then m:=b[i];
 writeln(m);
 readln;
end.
