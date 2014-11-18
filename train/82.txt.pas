var
h,n,m,i,j:longint;
b:array[1..2000]of boolean;
a,q:array[1..2000]of longint;
procedure qsort(l,r:longint);
var
t,x,i,j:longint;
begin
i:=l;j:=r;x:=q[(l+r) div 2];
repeat
while (q[i]<x) do i:=i+1;
while (x<q[j]) do j:=j-1;
if i<=j then
begin
t:=q[i];
q[i]:=q[j];
q[j]:=t;
i:=i+1;j:=j-1;
end;
until i>=j;
if l<j then qsort(l,j);
if r>i then qsort(i,r);
end;
begin
read(n,m);
h:=m;
for i:=1 to n do read(a[i]);
for i:=1 to m do read(q[i]);
qsort(1,m);
fillchar(b,sizeof(b),true);
for i:=1 to n do
for j:=m downto 1 do if (q[j]>0)and(b[j])and(q[j]<a[i]) then begin h:=h-1;b[j]:=false;break;end;
writeln(h);
end. 
