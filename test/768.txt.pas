program P1103;
var n,m,i,a,b,j,s:longint;
    f:array[0..10000] of boolean;
begin
 read(n,m);
 for i:=1 to m do
  begin
   read(a,b);
   for j:=a to b do f[j]:=true;
  end;
 for i:=0 to n do if f[i]<>true then inc(s);
 writeln(s);
end.
