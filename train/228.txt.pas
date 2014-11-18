program cannon;
const
  maxn=100;
var
  map:array[-1..maxn]of integer;
  val,w:array[1..100]of integer;
  m,n,numv:integer;

procedure init;
var
  i,j:integer;
  c:char;
begin
read(n,m);
fillchar(map,sizeof(map),0);
for i:=1 to n do
  begin
  readln;
  for j:=1 to m do
    begin
    read(c);
    map[i]:=map[i]shl 1;
    if c='H' then inc(map[i]);
    end;
  end;
end;

procedure value;
var
  i,j,k:integer;
  p:boolean;
begin
k:=0;numv:=1;
fillchar(val,sizeof(val),0);
fillchar(w,sizeof(w),0);
repeat
  p:=true;
  for i:=1 to m do
    if ((k shr(i-1))and 7)=0 then
      begin
      inc(k,1 shl(i-1));k:=(k shr(i-1))shl(i-1);
      inc(numv);val[numv]:=k;
      j:=k;
      while j>0 do
        begin
        if j and 1=1 then inc(w[numv]);
        j:=j shr 1;
        end;
      p:=false;
      break;
      end;
until p;
end;

procedure work;
var
  f:array[0..1,1..100,1..100]of integer;
  i,j,k,l,now,max:integer;
begin
fillchar(f,sizeof(f),0);
now:=0;
for i:=1 to numv do
  for j:=1 to numv do
    if (val[i]and map[1]=0)
       and(val[j]and map[2]=0)
       and(val[i]and val[j]=0)
    then f[now,i,j]:=w[i]+w[j];
for i:=3 to n do
  begin
  now:=1-now;
  for j:=1 to numv do
    for k:=1 to numv do
      for l:=1 to numv do
        if (val[j] and map[i-2]=0)
           and(val[k] and map[i-1]=0)
           and(val[l] and map[i]=0)
           and(val[j]or val[k]or val[l]=val[j]+val[k]+val[l])
           and(f[1-now,j,k]+w[l]>f[now,k,l])
        then f[now,k,l]:=f[1-now,j,k]+w[l];
  end;
max:=0;
for i:=1 to numv do
  for j:=1 to numv do
  if f[now,i,j]>max then max:=f[now,i,j];
write(max);
end;

begin
init;
value;
work;
end.
