program p1117;
const
 maxn=200;
 maxk=6;
var
 n,k,i,j:integer;
 f:array[0..maxn,0..maxk] of longint;
begin
 readln(n,k);
 f[0,0]:=1;
 for i:=1 to n do
f[i,1]:=1;
 for i:=1 to n do
for j:=1 to k do
  if i>=j
then f[i,j]:=f[i-1,j-1]+f[i-j,j];
 writeln(f[n,k]);
end. 

