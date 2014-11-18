program p1011;
const
  maxn=600;
type
  node=record
       h,r,c:longint;
       end;
var
  i,j,n,r,c,max:longint;
  a:array[0..maxn,0..maxn] of longint;
  b:array[0..maxn*maxn] of node;
  k:node;
  f:array[0..maxn,0..maxn] of longint;

procedure dp;
var
 i,j,k,x,y,h,a1,a2,a3,a4:longint;
begin
  fillchar(f,sizeof(f),0);
  f[b[n].r,b[n].c]:=1;

  for i:=n-1 downto 1 do
    begin
      k:=1;
      x:=b[i].r;
      y:=b[i].c;
      h:=b[i].h;
      if (x>1) and(a[x-1,y]>h) and(f[x-1,y]+1>k) then k:=f[x-1,y]+1;
      if (y<c) and(a[x,y+1]>h) and(f[x,y+1]+1>k) then k:=f[x,y+1]+1;
      if (x<r) and(a[x+1,y]>h) and(f[x+1,y]+1>k) then k:=f[x+1,y]+1;
      if (y>1) and(a[x,y-1]>h) and(f[x,y-1]+1>k) then k:=f[x,y-1]+1;
      f[x,y]:=k;
    end;
end;
procedure qsort(l,u:longint);
var
  i,j,k:longint;
  t:node;
begin
  i:=l;
  j:=u;
  k:=b[ (i+j)div 2].h;
  while i<=j do
    begin
      while b[i].h<k do inc(i);
      while b[j].h>k do dec(j);
      if i<=j then
        begin
          t:=b[i];
          b[i]:=b[j];
          b[j]:=t;
          inc(i);
          dec(j);
        end;
    end;
 if l<j then qsort(l,j);
 if i<u then qsort(i,u);
end;
begin

  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  readln(r,c);
  n:=0;
  for i:=1 to r do
  for j:=1 to c do
   begin
     read(a[i,j]);
     inc(n);
     b[n].r:=i;
     b[n].c:=j;
     b[n].h:=a[i,j];
   end;
{  for i:=1 to n-1 do
  for j:=i+1 to n do
    if b[i].h>b[j].h then
      begin
        k:=b[i];
        b[i]:=b[j];
        b[j]:=k;
      end;
      }
    qsort(1,n);
    dp;
  max:=0;
  for i:=1 to r do
  for j:=1 to c do
    if f[i,j]>max then max:=f[i,j];
  writeln(max);

end.

