program p1022;
var n,i,j,k:integer;
  g:array[1..200,1..200]of boolean;
  s:array[1..200]of integer;
begin
 readln(n);
 fillchar(g,sizeof(g),false);
 for i:= 1 to n do
  begin
   read(j);
   while j<>0 do
   begin
    g[i,j]:=true;
    read(j);
    end;
    end;
 for k:=1to n do
  for i:=1to n do
   for j:= 1 to n do
    g[i,j]:=g[i,j]or (g[i,k]and g[k,j]);
  k:=0;
   fillchar(s,sizeof(s),0);
   for i:= 1to n do
   if s[i]=0 then
   begin
    inc(k);s[i]:=k;
    for j:=1to n do
     if(g[i,j])and(g[j,i]) then s[j]:=s[i];
    end;
    writeln(k);
    end.
