var i,n,j,a:longint;
begin
readln(n);
  
i:=1;
a:=1;
while i<(n) do
begin
inc(a);
n:=n-i;
inc(i);
end;
if odd(a) then writeln(a-n+1,'/',n)
else writeln(n,'/',a-n+1);
end.
