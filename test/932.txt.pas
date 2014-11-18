var n,m,i:longint;
begin
readln(n);
if n=1 then begin  writeln(0);exit;end;
m:=trunc(ln(n)/ln(3))+1;
writeln(m);
end.
