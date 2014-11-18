var a,b:array[1..1000000]of char;
i,j,k,f,n,m:longint;
s:string;
begin
i:=1;
n:=0;
m:=0;
j:=1;
repeat
read(a[i]);
if (a[i]='W')or(a[i]='L') then inc(i);
until a[i]='E';
repeat
if a[j]='W' then n:=n+1;
if a[j]='L' then m:=m+1;
if ((m>=11)or(n>=11))and(abs(n-m)>=2) then begin
writeln(n,':',m);
n:=0;
m:=0;
end;
j:=j+1;
until j>i;
writeln(n,':',m);
writeln;
n:=0;
m:=0;
j:=1;
repeat
if a[j]='W'then n:=n+1;
if a[j]='L'then m:=m+1;
if ((m>=21)or(n>=21))and(abs(n-m)>=2) then begin
writeln(n,':',m);
n:=0;
m:=0;
end;
j:=j+1;
until j>i;
writeln(n,':',m);
end.               
