program q1;
var n:int64;
    max,k:real;
begin
 readln(k);max:=0;n:=1;
  while max<k do
   begin
    max:=1/n+max;
    inc(n);
   end;
write(n-1);
end.
