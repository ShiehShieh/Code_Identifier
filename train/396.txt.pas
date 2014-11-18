program p1023;
var
a:array[1..200,1..200] of boolean;
b:array[1..200] of boolean;
ans,n,k,i:integer;
procedure doit(k:integer);
var
i:integer;
begin
for i:=1 to n do
if a[k,i] then if not(b[i]) then begin b[i]:=true;doit(i);end;
end;
begin
readln(n);
ans:=0;
fillchar(a,sizeof(a),0);
fillchar(b,sizeof(b),0);
for i:=1 to n do
begin
k:=20000;
while not(k=0) do
begin
read(k);
if not(k=0) then a[i,k]:=true;
end;
readln;
end;
for i:=1 to n do
begin
if not(b[i]) then
begin
inc(ans);
doit(i)
end;
end;
writeln(ans);
end. 

