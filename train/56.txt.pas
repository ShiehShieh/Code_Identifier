var
i,j:longint;
k,m,n,t,d:int64;
a:array[0..21] of int64;
f:array[0..21] of integer;
begin
readln(n,m);
a[0]:=1;
for i:=1 to n do  a[i]:=a[i-1]*i;
k:=n+1;
repeat
k:=k-1;
d:=a[k-1];
t:=(m-1) div d+1;
m:=(m-1)mod d+1;
i:=0;
j:=0;
repeat
i:=i+1;
if f[i]=0 then inc(j);
until j=t;
write(i,' ');
f[i]:=1;
until k=3;
i:=0;
j:=0;
repeat
i:=i+1;
if f[i]=0 then inc(j);
until j=m;
write(i,' ');
f[i]:=1;
i:=0;  j:=0;
repeat
inc(i);
if f[i]=0 then inc(j);
until j=1;
write(i,' ');
f[i]:=1;
end.   
