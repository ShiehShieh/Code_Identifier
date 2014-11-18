type
arr=record
    x,y:real;
    end;
var
tp:arr;
p:array[1..1000]of arr;
f,dis:array[1..1000,1..1000]of real;
n,i,j:longint;
//////////////
procedure qsort(h,t:longint);
var
i,j:longint;
begin
i:=(h+t)shr 1;
tp:=p[i];p[i]:=p[h];p[h]:=tp;
i:=h;j:=t;
while i<j do
  begin
  while(i<j)and(tp.x<p[j].x)do dec(j);
  if i<j then
    begin
    p[i]:=p[j];inc(i);
    end;
  while(i<j)and(tp.x>p[i].x)do inc(i);
  if i<j then
    begin
    p[j]:=p[i];dec(j);
    end;
  end;
p[i]:=tp;
if h+1<i then qsort(h,i-1);
if i+1<t then qsort(i+1,t);
end;
//////////////
BEGIN
readln(n);
for i:=1 to n do
  readln(p[i].x,p[i].y);
if n>1 then qsort(1,n);
for i:=1 to n-1 do
  for j:=i+1 to n do
    dis[i,j]:=sqrt(sqr(p[j].x-p[i].x)+sqr(p[j].y-p[i].y));
f[2,1]:=dis[1,2];
for i:=3 to n do
  begin
  for j:=1 to i-2 do
    f[i,j]:=f[i-1,j]+dis[i-1,i];
  f[i,i-1]:=1e50;
  for j:=1 to i-2 do
    if f[i-1,j]+dis[j,i]<f[i,i-1] then f[i,i-1]:=f[i-1,j]+dis[j,i];
  end;
writeln(f[n,n-1]+dis[n-1,n]:0:2);
end.
