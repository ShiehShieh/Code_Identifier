const
inf=521015211;
var
g:array[-1..23,-1..23]of longint;
i,j,k,number,op,n,s:longint;
r,t:array[0..23]of longint;
d:array[-1..23]of longint;
function ford:boolean;
var
i,j,num:longint;
flag:boolean;
begin
for i:=-1 to 23 do
d[i]:=inf;
d[-1]:=0;
num:=1;
repeat
 flag:=true;
 for i:=-1 to 23 do
  for j:=-1 to 23 do
  if d[i]+g[i,j]<d[j]
  then begin
       flag:=false;
       d[j]:=d[i]+g[i,j];
       end;
 inc(num);
until (num=26)or(flag);
if (num=26)or(d[23]<k)
then exit(false)
else exit(true);
end;
begin
readln(number);
for op:=1 to number do
 begin
 fillchar(t,sizeof(t),0);
 for i:=0 to 23 do
 read(r[i]);
 readln(n);
 for i:=1 to n do
  begin
  readln(j);
  inc(t[j]);
  end;
 for i:=-1 to 23 do
  for j:=-1 to 23 do
  g[i,j]:=inf;
 for i:=0 to 23 do
  begin
  g[i-1,i]:=t[i];
  g[i,i-1]:=0;
  end;
 for i:=7 to 23 do
 g[i,i-8]:=-r[i];
 i:=-1;
 j:=n+1;
 while j-i>1 do
  begin
  k:=(i+j)shr 1;
  for s:=0 to 6 do
   g[s,s+16]:=-r[s]+k;
  if ford
  then j:=k
  else i:=k;
  end;
 if j=n+1
 then writeln('No Solution')
 else writeln(j);
 end;
end.

