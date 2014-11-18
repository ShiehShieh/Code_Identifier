var a,b,c,d,x:real;
    i:longint;
begin
 read(a,b,c,d);
 for i:=-10000 to 10000 do
  begin
   x:=i/100;
   if abs(a*x*x*x+b*x*x+c*x+d)<0.0001 then write(x:0:2,' ');
  end;
end.
