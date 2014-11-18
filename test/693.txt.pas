program chao;
 var a:array[-2..17,-2..17]of longint;
     b:array[-2..17,-2..17]of boolean;
     dx:array[1..8]of integer=(1,2,2,1,-1,-2,-2,-1);
     dy:array[1..8]of integer=(2,1,-1,-2,-2,-1,1,2);
     i,j,n,m,d1,d2:integer;

  begin
   readln(n,m,d1,d2);
   for i:=-2 to n+2 do
   for j:=-2 to m+2 do
    begin
     a[i,j]:=0;
     b[i,j]:=true;
    end;

   for i:=1 to 8 do
    b[d1+dx[i],d2+dy[i]]:=false;
   b[d1,d2]:=false;
   a[0,0]:=1;
   for i:=1 to n do if b[i,0] then a[i,0]:=a[i-1,0];
   for j:=1 to m do if b[0,j] then a[0,j]:=a[0,j-1];
   if (not b[0,0])or (not b[n,m]) then begin
    writeln('0');halt
   end;
   for i:=1 to n do
   for j:=1 to m do
   if b[i,j] then a[i,j]:=a[i-1,j]+a[i,j-1];
   writeln(a[n,m]);
  end.
