program p1011;
const
 maxn=500;
 dx:array[1..4]of longint=(0,-1,0,1);
 dy:array[1..4]of longint=(-1,0,1,0);
type
 node=record
      data,x,y:longint;
      end;
var
 sum:array[1..250000]of node;
 c:node;
 a,f:array[1..maxn,1..maxn]of longint;
 i,j,n,m,t,xx,yy,max,max1:longint;
procedure qsort(l,u:longint);
var
 i,j:longint;
 k,x:node;
begin
 i:=l;
 j:=u;
 k:=sum[(i+j)div 2];
 repeat
  while sum[i].data<k.data do inc(i);
  while sum[j].data>k.data do dec(j);
  if i<=j then
  begin
   x:=sum[i];
   sum[i]:=sum[j];
   sum[j]:=x;
   inc(i);
   dec(j);
  end;
 until i>j;
 if l<j then qsort(l,j);
 if i<u then qsort(i,u);
end;
procedure sort;
var
 i,j:longint;
 k:node;
begin
 for i:=1 to t-1 do
  for j:=i+1 to t do
   if sum[i].data>sum[j].data then
   begin
    k:=sum[i];
    sum[i]:=sum[j];
    sum[j]:=k;
   end;
end;
begin
   readln(n,m);
 for i:=1 to n do
  for j:=1 to m do
  begin
   inc(t);
   read(a[i,j]);
   sum[t].data:=a[i,j];
   sum[t].x:=i;
   sum[t].y:=j;
   f[i,j]:=0;
  end;
 qsort(1,t);
 for i:=1 to t do
 begin
  max1:=0;
  for j:=1 to 4 do
  begin
   xx:=sum[i].x+dx[j];
   yy:=sum[i].y+dy[j];
   if (xx=0)or(xx>n)or(yy=0)or(yy>m) then continue;
   if a[xx,yy]>=a[sum[i].x,sum[i].y] then continue;
   if f[xx,yy]>max1 then max1:=f[xx,yy];
  end;
  f[sum[i].x,sum[i].y]:=max1+1;
  if f[sum[i].x,sum[i].y]>max then
   max:=f[sum[i].x,sum[i].y];
 end;
 writeln(max);
 end.

