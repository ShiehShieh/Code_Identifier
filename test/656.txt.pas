program homework;
const
num=23137;
var
a,Q,P,two,prime:array[0..1000] of longint;
i,j,k,n,m,k1,k2,k3,ans,temp,total:longint;

function number(n,p:longint):longint;
var k:longint;
begin
number:=0; k:=p;
while k<=n do
     begin
     number:=number+n div k;
     k:=k*p;
     end;
end;

function c(n,m:longint):longint;
var
a:Array[0..200] of longint;
k:longint;
begin
if m>n then exit(0);
fillchar(a,sizeof(a),0);
for i:=1 to total do
  if prime[i]<=n then
       a[i]:=number(n,prime[i])-number(n-m,prime[i])-number(m,prime[i])
  else break;
k:=i-1;
c:=1;
for i:=1 to k do
     for j:=1 to a[i] do
          c:=c*prime[i] mod num;
end;

function c1(n,m:longint):longint;
var
a:Array[0..200] of longint;
i,j,k:longint;
begin
fillchar(a,sizeof(a),0);
for i:=1 to total do
  if prime[i]<=n then
       a[i]:=number(n,prime[i])-number(n-m,prime[i])-number(m,prime[i])
  else break;
k:=i-1; inc(m);
for i:=1 to k do
     begin
     while m mod prime[i]=0 do
          begin
          dec(a[i]);
          m:=m div prime[i];
          end;
     if m=1 then break;
     end;
c1:=1;
for i:=1 to k do
     for j:=1 to a[i] do
          c1:=c1*prime[i] mod num;
end;

procedure init;
begin
readln(k1,k2,k3);
two[0]:=1;
for i:=1 to k2 do
     two[i]:=two[i-1]shl 1 mod num;
for i:=2 to 1000 do
     begin
     k:=0;
     for j:=2 to trunc(sqrt(i)) do
          if i mod j=0 then
               begin k:=1; break; end;
     if k=0 then
          begin
          inc(total);
          prime[total]:=i;
          end;
     end;
temp:=c1(2*k1,k1);
end;

procedure plus;
var i:longint;
begin
fillchar(Q,sizeof(Q),0);
Q[2]:=2;
for i:=3 to k3 do
     Q[i]:=(Q[i-1]+Q[i-2]+a[i-2]shl 1+a[i-3]) mod num;
for i:=k3 downto 1 do
     a[i]:=(Q[i]+a[i]+a[i-1]) mod num;
end;

procedure work;
var t:longint;
begin
a[0]:=1; a[1]:=1;
for i:=2 to k3 do
     a[i]:=(a[i-1]+a[i-2]) mod num;
if k3=0 then P[0]:=1 else p[0]:=0;
P[1]:=a[k3];
for i:=2 to k1+1 do
     begin
     plus;
     P[i]:=a[k3];
     end;
ans:=0;
for t:=0 to k1+1 do
  if (k2-k1+t>0) then
     begin
     if (t=k1+1)and(k2=0) then
          k:=1
     else k:=c(k2-1,k2-k1-1+t)*two[k2-k1+t-1] mod num;
     k:=k*p[t] mod num;
     k:=c(k1+1,t)*k mod num;
     ans:=(ans+k) mod num;
     end;
ans:=ans*temp mod num;
writeln(ans);
end;

begin
init;
work;
end.

