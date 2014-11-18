program P1006;
const
 p1:array[0..5] of longint=(1,0,1,1,0,1);
 p2:array[0..5] of longint=(-1,-1,0,1,1,2);
var
 m,n,i,j,path,min,l,k,h1,h2,p00,p01:longint;
 a:array[1..1000,1..1000] of longint;
 w:array[1..1000,1..1000] of longint;
begin

 readln(n);
 for i:=1 to n do
  begin
   for j:=1 to i do
     read(a[i,j]);
   readln;
  end;
  for i:=0 to n+1 do
   for j:=0 to n+3 do
    w[i,j]:=2147483647;
   w[n,1]:=a[n,1];

   for i:=n downto 1 do
   for j:=1 to 20 do
    for k:=1 to i do
     begin
     p00:=1;p01:=4;
     if k=i then
      p01:=5;
     if k=1 then
      p00:=0;
      for l:=p00 to p01 do
       begin
        h1:=i+p1[l];h2:=k+p2[l];
        if h2=0 then h2:=i+p1[l];
        if h2=i+p1[l]+1 then h2:=1;
        if (w[h1,h2]<2147483647) and (a[i,k]<2147483647) then
         if w[h1,h2]+a[i,k]<w[i,k] then
          w[i,k]:=w[h1,h2]+a[i,k];
       end;
     end;
  writeln(w[1,1]);

end.



