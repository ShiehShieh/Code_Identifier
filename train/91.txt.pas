var
a,f:array[1..500,1..500]of longint;
n,m:longint;
function max(a,b:longint):longint;
begin
if a>b then exit(a) else exit(b);
end;
function dfs(x,y:longint):longint;
var
t1,t2,t3,t4:longint;
maxa:longint;
begin
if ((a[x-1,y]>a[x,y]) or (x-1=0)) and
((a[x+1,y]>a[x,y]) or (x+1>n)) and
((a[x,y-1]>a[x,y]) or (y-1=0)) and
((a[x,y+1]>a[x,y]) or (y+1>m)) then exit(1);
maxa:=0;
t1:=-1;
t2:=-1;
t3:=-1;
t4:=-1;
if (x+1<=n) and (a[x+1,y]<a[x,y]) then
begin
if (f[x+1,y]=-1) then
f[x+1,y]:=dfs(x+1,y);
t1:=f[x+1,y];
end;
if (x-1>=1) and (a[x-1,y]<a[x,y]) then
begin
if (f[x-1,y]=-1) then
f[x-1,y]:=dfs(x-1,y);
t2:=f[x-1,y];
end;
if (y+1<=m) and (a[x,y+1]<a[x,y]) then
begin
if (f[x,y+1]=-1) then
f[x,y+1]:=dfs(x,y+1);
t3:=f[x,y+1];
end;
if (y-1>=1) and (a[x,y-1]<a[x,y]) then
begin
if (f[x,y-1]=-1)  then
f[x,y-1]:=dfs(x,y-1);
t4:=f[x,y-1];
end;
maxa:=max(max(t1,t2),max(t3,t4));
f[x,y]:=maxa+1;
exit(f[x,y]);
end;
procedure main;
var
i,j,max:longint;
begin
read(n,m);
for i:=1 to n do
for j:=1 to m do
read(a[i,j]);
fillchar(f,sizeof(f),-1);
max:=0;
for i:=1 to n do
for j:=1 to m do
begin
if f[i,j]=-1 then f[i,j]:=dfs(i,j);
if f[i,j]>max then max:=f[i,j];
end;
if max=0 then inc(max);
writeln(max);
end;
begin
main;
end.

