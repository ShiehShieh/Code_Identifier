program p1143;

const
  way:array[1..8,1..3] of longint=
    ((-1,-1,-1),(-1,-1,0),(-1,0,-1),(0,-1,-1),(-1,0,0),(0,-1,0),(0,0,-1),(0,0,0));
  inf='1143.in';
  ouf='1143.out';

var
  a:array[0..30,0..30] of longint;
  f:array[0..50,0..30,0..30,0..30] of longint;
  n:longint;

procedure init;
var
  i,j:longint;
begin
  readln(n);
  for i:=1 to n do
   for j:=1 to n do read(a[i,j]);
  fillchar(f,sizeof(f),0);
end;

function find(i,j,k,l:longint):longint;
var
  max,t:longint;
  b:array[1..10] of longint;
begin
  find:=0;
  if (i-j+1>0) and (i-k+1>0) and (i-l+1>0) then
   begin
     fillchar(b,sizeof(b),0);
     for t:=1 to 8 do b[t]:=f[i-1,j+way[t,1],k+way[t,2],l+way[t,3]];
     max:=0;
     for t:=1 to 8 do if b[t]>max then max:=b[t];
     if j<>k
       then max:=max+a[j,i+1-j]+a[k,i+1-k]
       else max:=max+a[j,i+1-j];
     if (l<>k) and (l<>j) then max:=max+a[l,i+1-l];
     exit(max);
   end;
end;

procedure dp;
var
  i,j,k,l:longint;
begin
  //f[1,1,1,1]:=a[1,1];
  for i:=1 to 2*n-1 do
   for j:=1 to n do
    for k:=1 to n do
     for l:=1 to n do
       f[i,j,k,l]:=find(i,j,k,l);
end;

begin
  init;
  dp;
  write(f[2*n-1,n,n,n]);
end.
