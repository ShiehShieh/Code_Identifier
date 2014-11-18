program p1104;
var v,c,f:array[0..1000]of longint;
    t,m:longint;
    i,j,k:integer;
begin
 readln(t,m);
 for i:=1 to m do
  readln(c[i],v[i]);
 fillchar(f,sizeof(f),0);
 for i:=1 to m do
   begin
    for j:=t downto c[i] do
     if f[j-c[i]]+v[i]>f[j] then
      f[j]:=f[j-c[i]]+v[i];
   end;
writeln(f[t]);
end.


