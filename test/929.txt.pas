var
h:array[0..maxint]of longint;
a,b,t,d:array[0..100000]of longint;
n,m,x,i,j,max,maxt:longint;
begin
read(n,m);
for i:=1 to n do
begin
read(x);
inc(h[x]);
if x>maxt then maxt:=x;
end;
for i:=1 to m do
begin
read(a[i]);
inc(t[a[i]]);
if a[i]>max then max:=a[i];
end;
for i:=max-1 downto 1 do  t[i]:=t[i+1]+t[i];
for i:=1 to m do
begin
d[i]:=t[a[i]];
dec(t[a[i]]);
end;
i:=maxt;
j:=1;
while i>0 do
begin
inc(b[j],i);
dec(h[i]);
j:=(j+1) mod m;
if j=0 then j:=m;
while h[i]=0 do dec(i);
end;
for i:=1 to m do
write(b[d[i]],' ');
end.
