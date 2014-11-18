program seat(input,output); 
var 
a,b,c,d:array[1..10000] of longint; 
m,n,k,l,z,i,j,x,y,x1,y1:longint; 
procedure kp1(h,t:longint); 
var 
i,j,x,y:longint; 
begin 
x:=a[h]; 
y:=c[h]; 
i:=h; 
j:=t; 
while i<j do 
begin 
while (i<j)and(a[j]<x) do dec(j); 
if i<j then begin a[i]:=a[j]; c[i]:=c[j]; inc(i); end; 
while (i<j)and(a[i]>x) do inc(i); 
if i<j then begin a[j]:=a[i]; c[j]:=c[i]; dec(j); end; 
end; 
a[i]:=x; 
c[i]:=y; 
if i-1>h then kp1(h,i-1); 
if i+1<t then kp1(i+1,t); 
end; 
procedure kp2(h,t:longint); 
var 
i,j,x,y:longint; 
begin 
x:=b[h]; 
y:=d[h]; 
i:=h; 
j:=t; 
while i<j do 
begin 
while (i<j)and(b[j]<x) do dec(j); 
if i<j then begin b[i]:=b[j]; d[i]:=d[j]; inc(i); end; 
while (i<j)and(b[i]>x) do inc(i); 
if i<j then begin b[j]:=b[i]; d[j]:=d[i]; dec(j); end; 
end; 
b[i]:=x; 
d[i]:=y; 
if i-1>h then kp2(h,i-1); 
if i+1<t then kp2(i+1,t); 
end; 
procedure kp3(h,t:longint); 
var 
i,j,x:longint; 
begin 
x:=c[h]; 
i:=h; 
j:=t; 
while i<j do 
begin 
while (i<j)and(c[j]>x) do dec(j); 
if i<j then begin c[i]:=c[j]; inc(i); end; 
while (i<j)and(c[i]<x) do inc(i); 
if i<j then begin c[j]:=c[i]; dec(j); end; 
end; 
c[i]:=x; 
if i-1>h then kp3(h,i-1); 
if i+1<t then kp3(i+1,t); 
end; 
procedure kp4(h,t:longint); 
var 
i,j,x:longint; 
begin 
x:=d[h]; 
i:=h; 
j:=t; 
while i<j do 
begin 
while (i<j)and(d[j]>x) do dec(j); 
if i<j then begin d[i]:=d[j]; inc(i); end; 
while (i<j)and(d[i]<x) do inc(i); 
if i<j then begin d[j]:=d[i]; dec(j); end; 
end; 
d[i]:=x; 
if i-1>h then kp4(h,i-1); 
if i+1<t then kp4(i+1,t); 
end; 
begin 
readln(m,n,k,l,z); 
for i:=1 to n do 
c[i]:=i; 
for j:=1 to m do 
d[j]:=j; 
for i:=1 to z do 
begin 
read(x,y,x1,y1); 
if x=x1 then 
begin 
if y<y1 then inc(b[y]) 
else inc(b[y1]); 
end; 
if y=y1 then 
begin 
if x<x1 then inc(a[x]) 
else inc(a[x1]); 
end; 
end; 
kp1(1,n); 
kp2(1,m); 
kp3(1,k); 
kp4(1,l); 
for i:=1 to k-1 do 
write(c[i],' '); 
writeln(c[k]); 
for i:=1 to l-1 do 
write(d[i],' '); 
writeln(d[l]); 
end. 

