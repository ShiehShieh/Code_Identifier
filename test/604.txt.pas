const
  name='t4';
var
  i,j,k,m,n,s,a,b,tf:longint;
  ans:real;
  t:array[1..400,1..400] of real;
  x1,x2,x3,x4,y1,y2,y3,y4:longint;
  p:array[1..800,1..2] of longint;
  f:array[1..400,1..400] of real;
  ti:array[1..400] of longint;
begin

  readln(s,tf,a,b);
  m:=0;
  for i:= 1 to s do
    begin
      readln(x1,y1,x2,y2,x3,y3,ti[i]);
      inc(m);
      p[m,1]:=x1;
      p[m,2]:=y1;
      inc(m);
      p[m,1]:=x2;
      p[m,2]:=y2;
      inc(m);
      p[m,1]:=x3;
      p[m,2]:=y3;
      if (x1-x2)*(x3-x2)+(y1-y2)*(y3-y2)=0 then begin
        x4:=x1+x3-x2;
        y4:=y1+y3-y2;
      end;
      if (x1-x3)*(x2-x3)+(y1-y3)*(y2-y3)=0 then begin
        x4:=x1-x3+x2;
        y4:=y1-y3+y2;
      end;
      if (x2-x1)*(x3-x1)+(y2-y1)*(y3-y1)=0 then begin
        x4:=x2+x3-x1;
        y4:=y2+y3-y1;
      end;
      inc(m);
      p[m,1]:=x4;
      p[m,2]:=y4;
    end;
  for i:= 1 to m do
    for j:= 1 to m do
      if ((i-1) div 4)=((j-1) div 4) then t[i,j]:=ti[(i-1) div 4+1]*sqrt((p[i,1]-p[j,1])*(p[i,1]-p[j,1])+(p[i,2]-p[j,2])*(p[i,2]-p[j,2]))
        else t[i,j]:=tf*sqrt((p[i,1]-p[j,1])*(p[i,1]-p[j,1])+(p[i,2]-p[j,2])*(p[i,2]-p[j,2]));
  for i:= 1 to m do
    for j:= 1 to m do
      f[i,j]:=t[i,j];
  for k:= 1 to m do
    for i:= 1 to m do
      for j:= 1 to m do
        if f[i,j]>f[i,k]+f[k,j] then
          f[i,j]:=f[i,k]+f[k,j];
  ans:=maxint;
  for i:= 4*(a-1)+1 to 4*a do
    for j:= 4*(b-1)+1 to 4*b do
      if f[i,j]<ans then ans:=f[i,j];
  writeln(ans:0:2);

end.

