var
  i,m:longint;
  n:real;
begin
  read(m);
 for i:=1 to (m div 2) do
   begin
     n:=(0.5-i)+sqrt(sqr(i-0.5)+4*0.5*m);
     if n=trunc(n) then
       writeln(i,' ',(i+n-1):0:00);
   end;
end.

