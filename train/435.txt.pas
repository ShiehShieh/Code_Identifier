program temp;
const
maxn=1000000;
var
map:array[0..2000,0..2000]of longint;
dist,pre:array[0..2000]of longint;
v:array[0..2000]of boolean;
n,a,i,j,b,c,min,k:longint;
begin
readln(n);
readln(a,b,c);
for i:=1 to n do
for j:=1 to n do
map[i,j]:=-maxn;
map[a,b]:=c;
while (a<>0) or (b<>0) or (c<>0) do
begin
readln(a,b,c);
map[a,b]:=c;
end;
pre[1]:=0;
v[1]:=true;
for i:=2 to n do
begin
  dist[i]:=map[1,i];
  pre[i]:=1;
end;
for i:=1 to n do
begin
min:=-maxn;
for j:=1 to n do
if (dist[j]>min) and (not v[j]) then
begin
min:=dist[j];
k:=j;
end;
v[k]:=true;
for j:=1 to n do
if (map[k,j]>dist[j]) and (not v[j]) then
begin
dist[j]:=map[k,j];
pre[j]:=k;
end;
end;
for i:=2 to n do
begin
if dist[i]<>-maxn then
begin
min:=maxn;
k:=i;
while k<>1 do
begin
if map[pre[k],k]<min then min:=map[pre[k],k];
k:=pre[k];
end;
writeln(min)
end
else writeln('0');
end;


end.
