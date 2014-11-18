program p1143;
var
a:array[1..20,1..20] of longint;
f:array[0..40,0..20,0..20,0..20] of longint;
n,i,j,k,x,maxn:longint;
function max(t1,t2,t3,t4,t5,t6,t7,t8:longint):longint;
begin
max:=0;
if t1>max then max:=t1;
if t2>max then max:=t2;
if t3>max then max:=t3;
if t4>max then max:=t4;
if t5>max then max:=t5;
if t6>max then max:=t6;
if t7>max then max:=t7;
if t8>max then max:=t8;
end;

begin
readln(n);
for i:=1 to n do
 begin
  for j:=1 to n do
  read(a[i,j]);
  readln;
 end;
for x:=1 to n do
 for i:=1 to x do
  for j:=1 to x do
  for k:=1 to x do
   begin
    maxn:=max(f[x-1,i-1,j-1,k-1],
        f[x-1,i-1,j-1,k],
        f[x-1,i-1,j,k-1],
        f[x-1,i-1,j,k],
        f[x-1,i,j-1,k-1],
        f[x-1,i,j-1,k],
        f[x-1,i,j,k-1],
        f[x-1,i,j,k]);
    if i=j then
     if j=k then
    f[x,i,j,k]:=a[i,x+1-i]+maxn
     else
    f[x,i,j,k]:=a[i,x+1-i]+a[k,x+1-k]+maxn
    else
     if j=k then
    f[x,i,j,k]:=a[i,x+1-i]+a[j,x+1-j]+maxn
     else
    if i=k then
     f[x,i,j,k]:=a[j,x+1-j]+a[k,x+1-k]+maxn
    else
     f[x,i,j,k]:=a[i,x+1-i]+a[j,x+1-j]+a[k,x+1-k]+maxn;
   end;
for x:=n+1 to 2*n-1 do
 for i:=1 to 2*n-x do
  for j:=1 to 2*n-x do
  for k:=1 to 2*n-x do
   begin
    maxn:=max(f[x-1,i+1,j+1,k+1],
        f[x-1,i+1,j+1,k],
        f[x-1,i+1,j,k+1],
        f[x-1,i+1,j,k],
        f[x-1,i,j+1,k+1],
        f[x-1,i,j+1,k],
        f[x-1,i,j,k+1],
        f[x-1,i,j,k]);
    if i=j then
     if j=k then
    f[x,i,j,k]:=a[x-n+i,n+1-i]+maxn
     else
    f[x,i,j,k]:=a[x-n+i,n+1-i]+a[x-n+k,n+1-k]+maxn
    else
     if j=k then
    f[x,i,j,k]:=a[x-n+i,n+1-i]+a[x-n+j,n+1-j]+maxn
     else
    if i=k then
     f[x,i,j,k]:=a[x-n+j,n+1-j]+a[x-n+k,n+1-k]+maxn
    else
     f[x,i,j,k]:=a[x-n+i,n+1-i]+a[x-n+j,n+1-j]+a[x-n+k,n+1-k]+maxn;
   end;
writeln(f[2*n-1,1,1,1]);
end.

