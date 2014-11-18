var
  n,i:longint;
  s,ss:qword;
begin
  readln(n);
  s:=1; ss:=1;
  for i:= 2*n downto n+1 do
    s:=s*i;
  for i:= n downto 2 do
    ss:=ss*i;
  s:=s div ss;
  s:=s div (n+1);
  writeln(s);
end.

