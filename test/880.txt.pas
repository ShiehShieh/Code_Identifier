program p1433;
var
 a,b,c,d:int64;
begin
 readln(a,b,c,d);
 writeln((sqrt(sqr(sqrt(b)+sqrt(d))+sqr(a-c))):0:3);
end.
