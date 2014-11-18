var
n,i,j:longint;
a:array[0..2]of longint;
begin
read(n);
a[1]:=1;
j:=1;
for i:=1 to n-1 do
begin
j:=(j+1)mod 3;
a[j]:=(a[(j+2)mod 3]+a[(j+1)mod 3])mod 7654321;
end;
writeln(a[j])
end. 

