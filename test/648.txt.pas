program vijos1034;
var
 n,m,p,i,fy,fx,x,y,a,b:longint;
 fa:array[0..10000] of longint;
function get(v:longint):longint;
begin
 if fa[v]=v then get:=v
 else
 begin
fa[v]:=get(fa[v]);
get:=fa[v];
 end;
end;
begin
 readln(n,m,p);
 for i:=1 to n do fa[i]:=i;
 for i:=1 to m do
 begin
readln(x,y);
fx:=get(x);fy:=get(y);
fa[fy]:=fx;
 end;
 for i:=1 to p do
 begin
readln(a,b);
fx:=get(a);
fy:=get(b);
if fx=fy then writeln('Yes') else writeln('No');
 end;
end.
