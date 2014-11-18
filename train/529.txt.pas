var
 r,c,i,j,k,n,max:longint;
 h,f:array[0..501,0..501]of longint;

function search(x,y:longint):longint;{from (x,y),the longest way}
const
 xx:array[1..4]of integer=(-1,0,1,0);
 yy:array[1..4]of integer=(0,-1,0,1);
var i,t,tmp,nx,ny,k:longint;
begin
 if f[x,y]>0 then
begin
 search:=f[x,y];
 exit;
end;
 t:=1;
 for i:=1 to 4 do
   begin
 nx:=x+xx[i];
 ny:=y+yy[i];
 if (nx>0)and(nx<=r)and(ny>0)and(ny<=c)and(h[x,y]<h[nx,ny]) then
     begin
 tmp:=search(nx,ny)+1;
 if tmp>t then t:=tmp;
end;
end;
 f[x,y]:=t;
 search:=t;
end;

begin
 readln(r,c);
 max:=0;
 fillchar(f,sizeof(f),0);
 fillchar(h,sizeof(h),0);

 for i:=1 to r do
begin
  for j:=1 to c do
read(h[i,j]);
  end;
 for i:=1 to r do
for j:=1 to c do
   begin
  f[i,j]:=search(i,j);
  if f[i,j]>max then max:=f[i,j];
   end;
 writeln(max);
end.

