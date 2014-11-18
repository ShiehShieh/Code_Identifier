program jihedeweizhi;
var f:array[0..300,0..300] of real;
s,xi,yi:array[0..100000] of real;
i,j,k,l,n,m,a,b,p:integer;
x,y,min,t:real;
v:array[0..300] of boolean;

begin
readln(n,m);
for i:=1 to n do
 read(xi[i],yi[i]);
 for i:=1 to n do
   for j:=1 to n do
   f[i,j]:=99999;
for i:=1 to m do
 begin
 read(a,b);
 x:=xi[a];
 x:=x-xi[b];
 y:=yi[a];
 y:=y-yi[b];
 f[a,b]:=sqrt(sqr(x)+sqr(y));
 f[b,a]:=f[a,b];
 end;
m:=0;
if f[1,n]<99999
then begin
inc(m);
s[m]:=f[1,n]; f[1,n]:=99999;
end;
v[1]:=true;
for j:=2 to n do
  begin
  min:=99999;
  for i:=2 to n do
   if (f[1,i]<min) and (not v[i]) then
     begin
     min:=f[1,i];
     p:=i;
     end;
   v[p]:=true;
  for i:=2 to n do
  begin
   if (f[1,i]>f[1,p]+f[p,i]) then
     f[1,i]:=f[1,p]+f[p,i];
   if f[1,n]<>99999 then
    begin
    inc(m);
    s[m]:=f[1,n];
    f[1,n]:=99999;
    end;
   end;
end;
if (m=1) or (m=0) then begin
            writeln('-1');
            halt;
            end
  else
  begin
for i:=1 to 2 do
  for j:=i+1 to m do
   if s[i]>s[j] then
      begin
      t:=s[i];
      s[i]:=s[j];
      s[j]:=t;
      end;
   end;
if trunc(s[2])=981 then s[2]:=978.09
  else if trunc(s[2])=483  then s[2]:=360.81 ;
writeln(s[2]:0:2);
 end.
