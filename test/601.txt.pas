var i,j,k,n,m:longint;
    a:array[1..1000]of integer;
begin
 readln(n);
 for i:=1 to n do
  begin
   read(k);
   if a[k]=0
    then
     begin
      a[k]:=1;
      inc(m);
     end;
  end;
 writeln(m);
 for i:=1 to 1000 do
  if a[i]<>0 then
   write(i,' ');
end.

