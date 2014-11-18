program p1021;
var
 n,x,i,s,max,k:integer;
begin
 readln(n,k);
 max:=0;
 for i:=1 to n do
  begin
   S:=0;
   read(x);
   while x<>0 do
    begin
     read(x);
     inc(s);
    end;
   readln;
  if s>=k then inc(max);
  end;
 writeln(max);
end.
