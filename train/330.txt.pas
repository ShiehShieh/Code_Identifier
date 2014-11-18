type
longint=integer;
const
maxn=5000;
var
i,j,n,m,p,is,js:longint;
father:array[1..maxn]of longint;

function getfather(v:longint):longint;
begin
if father[v]=v then begin getfather:=v; exit; end;
father[v]:=getfather(father[v]);
getfather:=father[v];
end;

procedure merge(x,y:longint);
begin
x:=getfather(x);
y:=getfather(y);
father[x]:=y;
end;

function judge(x,y:longint):boolean;
begin
x:=getfather(x);
y:=getfather(y);
if x=y then judge:=true else judge:=false;
end;

begin
read(n,m,p);
for i:=1 to n do father[i]:=i;
for i:=1 to m do
begin
read(is,js);
merge(is,js);
end;
for i:=1 to p do
begin
read(is,js);
if judge(is,js) then writeln('Yes') else
writeln('No');
end;
end.

