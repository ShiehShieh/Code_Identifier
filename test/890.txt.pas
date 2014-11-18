program save;
var m:array[1..12] of integer;
    s1,i,s:integer;
begin
for i:=1 to 12 do
  readln(m[i]);
for i:=1 to 12 do
begin
  s:=s+300;
  s:=s-m[i];
  if s<0 then begin writeln('-',i); break; end;
  if s>=100 then s1:=s1+(s div 100*100); s:=s mod 100;
end;
if s>=0 then begin s:=s+(s1 div 10*12); write(s:0); end;
end.
