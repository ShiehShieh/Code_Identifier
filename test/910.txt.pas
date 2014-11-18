var
  n,t,i,v:longint;
  x,y,f:array[1..10000]of int64;
function  max(a,b:longint):longint;
 begin
   if a>b then exit(a) else exit(b);
 end;
begin
  readln(n);
  readln(t);
  for i:=1 to n do readln(x[i],y[i]);
  for i:=1 to n do
    for v:= t downto y[i] do
      if v-y[i]>=0 then f[v]:=max(f[v],f[v-y[i]]+x[i]);
  writeln(f[t]);
end.
