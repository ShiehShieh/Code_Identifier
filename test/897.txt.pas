program vijos1441;
var
  i,j,k,m,n,p,max,t:longint;
  f,time,x,y:array[0..10000] of longint;
begin
  read(n,m);
  for i:=1 to m do
   read(time[i],x[i],y[i]);
  for i:=1 to m do
   begin
    p:=0;
    for j:=1 to i-1 do
     begin
      t:=abs(x[i]-x[j])+abs(y[i]-y[j]);
      if (t<=time[i]-time[j])and(f[j]+1>p) then p:=f[j];
     end;
    f[i]:=p+1;
    if f[i]>max then max:=f[i];
   end;
  writeln(max);
end.


