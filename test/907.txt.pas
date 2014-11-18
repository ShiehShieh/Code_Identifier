   Program P1051;
const
 a:array[1..12,1..2] of integer=((-2,0),(-1,0),(2,0),(1,0),(0,1),(0,2),(0,-1),(0,-2),(-1,-1),(1,1),(-1,1),(1,-1));

 var f:array[-1..102,-1..102] of char;
       n,m,i,j,s:integer;
 Procedure search(x,y:integer);
  var t:integer;
  begin
   f[x,y]:='-';
   for t:=1 to 12 do
    if (f[x+a[t,1],y+a[t,2]]='#')and(x+a[t,1]<=n)and(x+a[t,1]>0)and(y+a[t,2]<=m)and(y+a[t,2]>0)
     then
         search(x+a[t,1],y+a[t,2]);
  end;
begin
 readln(n,m);
 for i:=1 to n do
  begin
   for j:=1 to m do read(f[i,j]);
   readln;
  end;
 for i:=1 to n do
  for j:=1 to m do
   if f[i,j]='#'
    then begin
           inc(s);
           search(i,j);
         end;
 writeln(s);
end.    
