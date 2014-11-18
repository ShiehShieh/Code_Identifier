var i,j,k,m,n,t:longint;
    v,p,q:array[0..61]of longint;
    f,w,v2:array[0..61,0..3201]of longint;
begin
read(n,m);n:=n div 10;
for i:=1 to m do
  begin read(v[i],p[i],q[i]);v[i]:=(v[i] div 10);end;


for i:=1 to m do
   if q[i]=0 then begin w[i,0]:=v[i]*p[i];v2[i,0]:=v[i];end
     else if w[q[i],1]=0 then begin w[q[i],1]:=w[q[i],0]+v[i]*p[i];v2[q[i],1]:=v[q[i]]+v[i];end
          else begin w[q[i],2]:=w[q[i],0]+v[i]*p[i];v2[q[i],2]:=v[q[i]]+v[i];
                      w[q[i],3]:=w[q[i],1]+w[q[i],2]-w[q[i],0];v2[q[i],3]:=v2[q[i],1]+v[i];
               end;

for i:=1 to m do
 begin
  for j:=0 to n do
   begin
    if q[i]=0 then
      f[i,j]:=f[t,j];
      for k:=0 to 3 do
        if  (j>=v2[i,k]) then
         if (f[i,j]<f[t,j-v2[i,k]]+w[i,k]) then
          f[i,j]:=f[t,j-v2[i,k]]+w[i,k];
   end;
  t:=i;
 end;
write(f[t,n]*10);

end.

