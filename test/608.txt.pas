var
n,i:integer;
a:array[1..1000]of longint;
begin
readln(n);
a[1]:=1;
for i:=2 to n do begin
a[i]:=a[i-1]+((i+1)mod 2)*a[i div 2];
end;
writeln(a[n]);
end.
