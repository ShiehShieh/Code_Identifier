type
 node=record
  w,w1,w2:longint;
 end;
var
 f:array[0..60,0..32000] of longint;
 c,d,a,b:array[1..60] of node;
 t,r,i,j,k,m,n,max:longint;
 begin
  readln(n,m);
  for i:=1 to m do
   begin
    readln(j,k,r);
    if r=0 then begin a[i].w:=j;b[i].w:=k;end
    else
     if a[r].w1=0 then begin a[r].w1:=j;b[r].w1:=k;end
      else
       begin
        a[r].w2:=j;b[r].w2:=k;
       end;
   end;
  t:=0;
  for i:=1 to m do
   if a[i].w<>0 then
    begin
     t:=t+1;
     c[t]:=a[i];
     d[t]:=b[i];
    end;
  {for i:=1 to t do
   writeln(c[i].w,' ',c[i].w1,' ',c[i].w2);}
  fillchar(f,sizeof(f),0);
  for i:=1 to t do
   for j:=0 to n do
    begin
     max:=f[i-1,j];
     if (j>=c[i].w) and (f[i-1,j-c[i].w]+c[i].w*d[i].w>max) then max:=f[i-1,j-c[i].w]+c[i].w*d[i].w;

     if (c[i].w1<>0) and (j>=c[i].w+c[i].w1) and (f[i-1,j-c[i].w-c[i].w1]+c[i].w*d[i].w+c[i].w1*d[i].w1>max) then
      max:=f[i-1,j-c[i].w-c[i].w1]+c[i].w*d[i].w+c[i].w1*d[i].w1;

     if (c[i].w2<>0) and (j>=c[i].w+c[i].w2) and (f[i-1,j-c[i].w-c[i].w2]+c[i].w*d[i].w+c[i].w2*d[i].w2>max) then
      max:=f[i-1,j-c[i].w-c[i].w2]+c[i].w*d[i].w+c[i].w2*d[i].w2;

     if (c[i].w1<>0) and (c[i].w2<>0) and (j>=c[i].w+c[i].w1+c[i].w2) and
      (f[i-1,j-c[i].w-c[i].w1-c[i].w2]+c[i].w*d[i].w+c[i].w1*d[i].w1+c[i].w2*d[i].w2>max) then
       max:=f[i-1,j-c[i].w-c[i].w1-c[i].w2]+c[i].w*d[i].w+c[i].w1*d[i].w1+c[i].w2*d[i].w2;
     f[i,j]:=max;
   end;
  writeln(f[t,n]);
 end.





