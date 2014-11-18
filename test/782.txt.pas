program a1;
var w,n,m,i,k,j:integer;
    ww,mm,kk:array [0..400] of longint;
    f:array [0..400,0..400] of longint;
function max(x,y:integer):integer;
begin
 if x>y then max:=x else max:=y;
end;
begin
 readln(w,m);
 read(n);
 for i:=1 to n do
  readln(ww[i],mm[i],kk[i]);
 for i:=1 to n do
   for j:=w downto ww[i] do
    for k:=m downto mm[i] do
      f[j,k]:=max(f[j,k],f[j-ww[i],k-mm[i]]+kk[i]);
 write(f[w,m]);
end.
