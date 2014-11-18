var
 n,v,s,t:real;
 i1,i2,i3,i4,k,x1,x2,x3,x4:integer;
 begin
  n:=5000;
  readln(k,x1,x2,x3,x4);
  for i1:=0 to 10 do
  for i2:=0 to 10 do
  for i3:=0 to 10 do
  for i4:=0 to 10 do
  if i1+i2+i3+i4<=k then begin
                               v:=(100-i2*7)*x2*2+(100-i3*9)*x3;
                               s:=(10+i4*1)*x4;
                               t:=(v/s)+((20-i1*2)*x1);
                               if n>t then n:=t;
                        end;


  write(n:0:3);
 end.
