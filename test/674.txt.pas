program aa;
type
  t1=array [1..10] of integer;
var
  x:t1;a,i,j:integer;
begin
 for i:=1 to 10 do
 read(x[i]);
 readln(a);
 i:=0;
 j:=0;
 repeat
 i:=i+1;
 if a+30>=x[i] then
 j:=j+1;
 until i=10;
 writeln(j);
 end.
