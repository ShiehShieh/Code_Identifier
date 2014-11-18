PROGRAM jinming;
VAR
 m,n,x,i,t1,t2,j,k1,k2,k3:longint;
 w,v:array[0..60,0..2] of longint;
 f:array[0..32000]of longint;
FUNCTION max(a,b:longint):longint;
begin
 max:=a;
 if b>max then max:=b;
end;
BEGIN
 readln(n,m);
 fillchar(f,sizeof(f),0);
 t1:=0;
 for i:=1 to m do begin
readln(k1,k2,k3);
if k3=0 then begin
  inc(t1);
  w[i,0]:=k2;
  v[i,0]:=k1;
end
else begin
  t2:=1;
  while w[k3,t2]<>0 do inc(t2);
  w[k3,t2]:=k2;
  v[k3,t2]:=k1;
end;
 end;
 for i:=1 to m do
for j:=n downto v[i,0]  do begin

  f[j]:=max(f[j],
  f[j-v[i,0]]+w[i,0]*v[i,0]);

  if (v[i,1]<>0)and(j>=v[i,0]+v[i,1])then
f[j]:=max(f[j],
f[j-v[i,0]-v[i,1]]+w[i,0]*v[i,0]+w[i,1]*v[i,1]);

  if v[i,2]<>0 then begin
if (j>=v[i,0]+v[i,2])then
  f[j]:=max(f[j],
  f[j-v[i,0]-v[i,2]]+w[i,0]*v[i,0]+w[i,2]*v[i,2]);

if (j>=v[i,0]+v[i,1]+v[i,2])then
  f[j]:=max(f[j],
  f[j-v[i,0]-v[i,1]-v[i,2]]+w[i,0]*v[i,0]+w[i,1]*v[i,1]+w[i,2]*v[i,2]);

  end;
end;
 write(f[n]);
END.

