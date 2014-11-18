program caiyao;
var tz,m,i,j,k:integer;
    f:array[0..100,0..1000] of longint;
    t,p:array[1..100] of integer;
function max(a,b:longint):longint;
begin
if a>b then max:=a else max:=b;
end;{max}
begin
readln(tz,m);
for i:=1 to m do readln(t[i],p[i]);
//for i:=1 to m do f[0,i]:=0;
//for i:=1 to tz do f[i,0]:=0;
f[0,tz]:=0;
for i:=1 to m do
  for j:=1 to tz do
    if j-t[i]>=0 then f[i,j]:=max(f[i-1,j],f[i-1,j-t[i]]+p[i])
                else f[i,j]:=f[i-1,j];
writeln(f[m,tz]);
end.

