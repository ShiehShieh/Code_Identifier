program temp;
var
a:array[1..30000] of integer;
w,n,i,j,s:integer;
procedure qsort(h,t:integer);
var
p,i,j:integer;
begin
i:=h;
j:=t;
p:=a[i];
repeat
while (a[j]>p) and (j>i) do j:=j-1;
if j>i then
begin
a[i]:=a[j];
i:=i+1;
while (a[i]<p) and (i<j) do i:=i+1;
if i<j then
begin
a[j]:=a[i];
j:=j-1;
end;
end;
until i=j;
a[i]:=p;
i:=i+1;
j:=j-1;
if i<t then qsort(i,t);
if j>h then qsort(h,j);
end;
begin
readln(w);
readln(n);
for i:=1 to n do readln(a[i]);
qsort(1,n);
i:=1;
j:=n;
s:=0;
while i<=j do
begin
if i=j then
begin
s:=s+1;
break;
end;
if a[i]+a[j]<=w then
begin
i:=i+1;
j:=j-1;
s:=s+1;
end;
if a[i]+a[j]>w then
begin
s:=s+1;
j:=j-1;
end;
end;
writeln(s);
end.
