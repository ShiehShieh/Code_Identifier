var
a:array[1..10001] of integer;
m,n,i,j,p,q,t:integer;
begin
readln(n);
readln(m);
for i:=1 to n do read(a[i]);
for i:=1 to m do
begin
p:=n-1;
while a[p]>a[p+1] do dec(p);
q:=p+1;
while (q<=n) and (a[q]>a[p]) do
inc(q);
dec(q);
t:=a[p];
a[p]:=a[q];
a[q]:=t;
for j:=p+1 to p+(n-p) div 2 do
begin
t:=a[j];
a[j]:=a[n+p+1-j];
a[n+p+1-j]:=t;
end;
end;
for i:=1 to n do
if not(i=n) then write(a[i],' ')
else writeln(a[i]);
end.
