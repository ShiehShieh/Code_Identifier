program p1423;
var n,m,min,k,x,y,b,i,j:longint;
    a:array[1..200]of integer;
    g,d:array[1..200,1..200]of longint;
begin
     readln(n,m);
   for i:=1 to n do
    read(a[i]);
   fillchar(g,sizeof(g),0);
    for i:=1 to n do
     for j:=1 to n do
      d[i,j]:=21374836;
   for i:=1to m do
    begin
     readln(x,y,b);
     if (g[x,y]=0)or (g[x,y]>b+a[x])then
     begin
      g[x,y]:=b+a[x];
      d[x,y]:=g[x,y];
      end;
    end;
    for k:=1 to n do
     for i:=1 to n do
      if i<>k then
       for j:=1to n do
        if (j<>k)and(j<>i) then
        if d[i,j]>d[i,k]+d[k,j] then
         d[i,j]:=d[i,k]+d[k,j];
       min:=21374836;
     for i:=2 to n do
      if (d[1,i]+d[i,1]<min) then min:=d[1,i]+d[i,1];
      if min=21374836 then write('-1') else write(min);
      end.
