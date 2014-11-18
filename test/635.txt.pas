program d3_5;
var
  s1,s2:qword;
  n,a,b,i:longint;
begin
  readln(n,a,b);
  s1:=1;
  for i:=1 to a do
    s1:=s1*(n+i) div i;
  s2:=1;
  for i:=1 to b do
    s2:=s2*(n+i) div i;
  writeln(s1*s2);
end.
