program apple;
var h,i,j,s:integer;
    a:array[1..10]of integer;
begin
 j:=0;
 for i:=1 to 10 do
  begin
   read(s);
   a[i]:=s;
  end;
 readln;
 read(s);
 for i:=1 to 10 do
  if a[i]<=s+30 then j:=j+1;
 writeln(j);
end.
