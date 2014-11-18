program rq331;
 var
  n,m,p,i,j,x,y:longint;
  c:array [1..5000] of longint;
 function find(a:longint):longint;
  begin
   if c[a]=a then find:=a
    else find:=find(c[a]);
   c[a]:=find;
  end;
 begin
  readln(n,m,p);
  for i:=1 to n do
   c[i]:=i;
  for i:=1 to m do
   begin
    readln(x,y);
    if c[x]<>c[y] then c[find(x)]:=c[find(y)];
   end;
  for i:=1 to p do
   begin
    readln(x,y);
    if find(x)=find(y) then writeln('Yes') else writeln('No');
   end;
  readln;
  end.      
