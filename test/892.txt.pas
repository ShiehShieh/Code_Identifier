program P1113;
var
  i,j,k:longint;
begin
  for i:=1 to 7 do
  begin
    read(j,k);
    if j+k>8 then begin writeln(i);exit end;
  end;
end. 
