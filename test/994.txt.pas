program lx;
var
  i,k:longint;
  max:real;
begin
  readln(k);
  for i:=1 to 999999 do
  begin
    max:=max+1/i;
    if max>k then break;
  end;
  writeln(i);
end.
