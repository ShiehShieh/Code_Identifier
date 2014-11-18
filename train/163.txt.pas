type
arr1=array[1..125]of longint;
var
st:string;
a,b:arr1;
e:array[1..30]of 0..1;
i2,j2,n,m,l,h,l1,jj:longint;
procedure cheng(var c,d:arr1);
var
i,j,k1:integer;
f:arr1;
begin
fillchar(f,sizeof(f),0);
for i:=1 to 125 do begin
k1:=0;
for j:=1 to 125-i+1 do begin
f[i+j-1]:=f[i+j-1]+c[i]*d[j]+k1;
k1:=f[i+j-1] div 10000;
f[i+j-1]:=f[i+j-1] mod 10000;
end;
end;
c:=f;
end;
begin
readln(n);
m:=n;
l:=0;
while m>0 do begin
l:=l+1;
e[l]:=m mod 2;
m:=m div 2;
end;
a[1]:=2;
if e[1]=1 then b[1]:=2 else b[1]:=1;
for i2:=2 to l do begin
cheng(a,a);
if e[i2]=1 then
cheng(b,a);
end;
a:=b;
a[1]:=a[1]-1;
writeln(trunc(n*ln(2)/ln(10))+1);
jj:=0;
for i2:=125 downto 1 do begin
str(a[i2],st);
l1:=length(st);
if l1<4 then
for j2:=1 to 4-l1 do st:='0'+st;
for j2:=1 to 4 do begin
jj:=jj+1;
write(st[j2]);
if jj mod 50=0 then writeln;
end;
end;
end.

