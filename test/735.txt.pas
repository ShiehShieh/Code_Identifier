PRogram P1323;
const
  w:string='ABC';
var
  f:array [0..100,0..10,0..10,0..10] of longint;
  r:array [0..100,1..3] of longint;
  a:array [0..100] of longint;
  n,i,j:longint;

Procedure INit;
var
  i,j:longint;
  ch:char;
begin
  fillchar(r,sizeof(r),0);
  readln(n);
  for i:=1 to n do
    begin
      readln(ch);
      a[i]:=pos(ch,w);
      for j:=1 to 3 do
        r[i,j]:=r[i-1,j];
      inc(r[i,a[i]]);
    end;
end;

PRocedure Run(p,i,j,k,now:longint);
var
  d:longint;
begin
  if now>=f[p,i,j,k] then exit;
  f[p,i,j,k]:=now;
  if p=n then
    begin
      d:=0;
      if i>0 then inc(d);
      if j>0 then inc(d);
      if k>0 then inc(d);
      if d=0 then exit;
      Run(p,0,0,0,now+d);
    end else
    begin
      if i>0 then
        if p+i<=n then
          Run(p+i,r[p+i,1]-r[p,1],j+r[p+i,2]-r[p,2],k+r[p+i,3]-r[p,3],now+1)
            else
          Run(n,r[n,1]-r[p,1],j+r[n,2]-r[p,2],k+r[n,3]-r[p,3],now+1);
      if j>0 then
        if p+j<=n then
          Run(p+j,i+r[p+j,1]-r[p,1],r[p+j,2]-r[p,2],k+r[p+j,3]-r[p,3],now+1)
            else
          Run(n,i+r[n,1]-r[p,1],r[n,2]-r[p,2],k+r[n,3]-r[p,3],now+1);
      if k>0 then
        if p+k<=n then
          Run(p+k,i+r[p+k,1]-r[p,1],j+r[p+k,2]-r[p,2],r[p+k,3]-r[p,3],now+1)
            else
          Run(n,i+r[n,1]-r[p,1],j+r[n,2]-r[p,2],r[n,3]-r[p,3],now+1);
    end;
end;

begin
  INit;
  fillchar(f,sizeof(f),12);
  j:=10;
  if n<j then j:=n;
  for i:=1 to j do
    Run(i,r[i,1],r[i,2],r[i,3],0);
  writeln(f[n,0,0,0]);
end.
