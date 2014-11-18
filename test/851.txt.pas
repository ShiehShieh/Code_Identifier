program gongyueshu;
var
  x,y,y1,i,t,a,b,c:longint;
begin
  readln(x,y);
  y1:=y div x;
  if y mod x =0 then
    for i:=1 to y1 do
      if y1 mod i =0 then
        begin
          a:=i;
          b:=y1 div i;
          c:=a mod b;
          while c<>0 do
            begin
              a:=b;
              b:=c;
              c:=a mod b;
            end;
            if b=1 then inc(t);
        end;
  writeln(t);
end.
