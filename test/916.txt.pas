program p1303; 
var 
a:array[1..100,1..100] of longint; 
w,c:array[1..100] of longint; 
s:string; 
i,j,t,max,min,m,k:longint; 
procedure try(k,s,n:longint); 
var 
i:longint; 
begin 
if k>t then 
begin 
if s>max then max:=s; 
exit; 
end; 
if w[k]<=n then try(k+1,s+1,w[k]); 
try(k+1,s,n); 
end; 
begin 
readln(s); 
s:=s+','; 
j:=1; 
for i:=1 to length(s) do 
if s[i]=',' then 
begin 
inc(t); 
val(copy(s,j,i-j),w[t]); 
j:=i+1; 
end; 
for i:=1 to t do 
try(i+1,1,w[i]); 
write(max,','); 
c[1]:=1; 
a[1,1]:=w[1]; 
m:=1; 
for i:=2 to t do 
begin 
min:=30001; 
for j:=1 to m do 
if (w[i]<=a[j,c[j]])and(a[j,c[j]]<min) then 
begin 
min:=a[j,c[j]]; 
k:=j; 
end; 
if min=30001 then 
begin 
inc(m); 
a[m,1]:=w[i]; 
c[m]:=1; 
end 
else 
begin 
inc(c[k]); 
a[k,c[k]]:=w[i]; 
end; 
end; 
write(m-1); 
end.
