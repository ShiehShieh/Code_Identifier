var
l,n,k,i,j:longint;
s:char;
a:array[0..40]of longint;
d:array[0..41,0..41]of longint;
f:array[0..41,0..7]of longint;
begin
readln(n,k);
for i:=1to n do
begin
read(s);
a[i]:=ord(s)-ord('0');
d[i,i]:=a[i];
end;
for i:=1to n do
for j:=i+1to n do
d[i,j]:=d[i,j-1]*10+a[j];
for i:=1to n do
f[i,0]:=d[1,i];
for i:=1to k do
for j:=1to n do
for l:=i to j-1do
if f[l,i-1]*d[l+1,j]>f[j,i]
then f[j,i]:=f[l,i-1]*d[l+1,j];
writeln(f[n,i]);
end. 

