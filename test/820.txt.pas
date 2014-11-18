var
m,s,t:longint;
s0,t0:longint;
begin
readln(m,s0,t0);
t:=0;
repeat
inc(t);
if m>=10 then
 begin
inc(s,60);dec(m,10)
 end
 else
if ((t0-t)*4+m)<10 then inc(s,17)
 else
if ((s0-s)<=17) or ((s0-s)<=34) and (m<6) or ((s0-s<=68) and (m<2))
 then inc(s,17)
 else
inc(m,4);
until (t=t0) or (s>=s0);
if s>=s0 then begin
writeln('Yes');
writeln(t) ;exit;
   end;
writeln('No');
writeln(s);
end.

