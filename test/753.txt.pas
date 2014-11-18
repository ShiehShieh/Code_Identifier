program p1097;
var n,i:integer;
a:array[0..10001] of longint;
ans:int64;
procedure p1(l,r:integer);
var i,j:integer;
    x,g:longint;
begin
i:=l;j:=r;x:=a[(l+r) shr 1];
repeat
while a[i]<x do inc(i);
while x<a[j] do dec(j);
if i<=j then begin
g:=a[i];
a[i]:=a[j];
a[j]:=g;
inc(i);dec(j);
end;
until i>j;
if l<j then p1(l,j);
if i<r then p1(i,r);
end;
procedure p2(now:integer);
var g:longint;
begin
while (a[now]>a[now+1]) and (now<n) do
begin
g:=a[now];a[now]:=a[now+1];a[now+1]:=g;
inc(now);
end;
end;
begin
readln(n);
for i:=1 to n do
read(a[i]);
p1(1,n);
ans:=0;
for i:=2 to n do
begin
inc(a[i],a[i-1]);
ans:=ans+a[i];
p2(i);
end;
writeln(ans);
end.
