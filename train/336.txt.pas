program shudu;
 const num=1 shl 9-1;
two:array[0..8] of integer=(1,2,4,8,16,32,64,128,256);
 type
zuobiao=record
  i,j:integer;
end;
 var h,l,q:array[1..9] of integer;
  a,qu:array[1..9,1..9] of integer;
  b:array[1..81] of zuobiao;
  n,m:integer;
  flag:boolean;
 procedure pre;
var i,j,p,q,k:integer;
begin
  k:=0;
  for p:=1 to 3 do
for q:=1 to 3 do
  begin
inc(k);
for i:=(p-1)*3+1 to p*3 do
  for j:=(q-1)*3+1 to q*3 do
qu[i,j]:=k;
  end;
end;
 procedure init;
var i:integer;
begin
  flag:=false;
  m:=0;
  fillchar(a,sizeof(a),0);
  fillchar(h,sizeof(h),0);
  fillchar(l,sizeof(l),0);
  fillchar(q,sizeof(q),0);
end;
 procedure dushu;
var i,j,k,o:integer;
s:string;
begin
  readln(s);
  o:=0;
  for i:=1 to 9 do
for j:=1 to 9 do
  begin
inc(o);
a[i,j]:=ord(s[o])-48;
if a[i,j]<>0 then
  begin
h[i]:=h[i]+1 shl (a[i,j]-1);
l[j]:=l[j]+1 shl (a[i,j]-1);
k:=qu[i,j];
q[k]:=q[k]+1 shl (a[i,j]-1);
  end
else
  begin
inc(m);
b[m].i:=i;
b[m].j:=j;
  end;
  end;
end;
 function find(i:integer):integer;
var p,q,x:integer;
begin
  p:=0;q:=8;
  while p<=q do
begin
  x:=(p+q) div 2;
  if two[x]=i then exit(x+1);
  if two[x]<i then p:=x+1
  else q:=x-1;
end;
end;
 procedure outp;
var i,j:integer;
begin
  for i:=1 to 9 do
for j:=1 to 9 do
  write(a[i,j]);
  writeln;
end;
 procedure solve(k:integer);
var p,pos,i,j,kk:integer;
begin
  if k>m then
begin
  outp;
  flag:=true;
  exit;
end;
  i:=b[k].i;
  j:=b[k].j;
  pos:=num and not (h[i] or l[j] or q[qu[i,j]]);
  while pos<>0 do
begin
  p:=pos and -pos;
  pos:=pos-p;
  h[i]:=h[i]+p;
  l[j]:=l[j]+p;
  q[qu[i,j]]:=q[qu[i,j]]+p;
  a[i,j]:=find(p);
  solve(k+1);
  if flag then exit;
  a[i,j]:=0;
  h[i]:=h[i]-p;
  l[j]:=l[j]-p;
  q[qu[i,j]]:=q[qu[i,j]]-p;
end;
end;
 procedure main;
var i:integer;
begin
  pre;
  readln(n);
  for i:=1 to n do
begin
  init;
  dushu;
  solve(1);
end;
end;
 begin
main;
 end.

