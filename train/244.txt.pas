var x0,y0,x1,y1,n,m,i,j:longint;
f:array[1..1000,1..1000]of int64;
function dfs(x,y:longint):int64;
begin
if f[x,y]>=0 then exit(f[x,y]);
f[x,y]:=0;
if (x+1<=x1)and(y+2<=m) then inc(f[x,y],dfs(x+1,y+2));
if (x+1<=x1)and(y-2>0) then inc(f[x,y],dfs(x+1,y-2));
if (x+2<=x1)and(y+1<=m) then inc(f[x,y],dfs(x+2,y+1));
if (x+2<=x1)and(y-1>0) then inc(f[x,y],dfs(x+2,y-1));
dfs:=f[x,y]
end;
begin
read(n,m,x0,y0,x1,y1);
for i:=1 to x1-1 do
for j:=1 to m do f[i,j]:=-1;
f[x1,y1]:=1;
if dfs(x0,y0)=0 then write('NO') else write(f[x0,y0],'00000000')
end.  
