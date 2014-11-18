var
a:array[1..15000]of record
x,y:longint;
end;
b:array[0..14999]of longint;
n,i,j,t:longint;
begin
readln(n);
for i:=1 to n do begin read(a[i].x);read(a[i].y);end;
for i:=1 to n do
begin
t:=0;
for j:=1 to n do
if (j<>i)and(a[i].x>=a[j].x)and(a[i].y>=a[j].y) then t:=t+1;
b[t]:=b[t]+1;
end;
for i:=0 to n-1 do writeln(b[i]);
end. 

