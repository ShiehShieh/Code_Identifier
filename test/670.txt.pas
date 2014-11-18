var
  b:array[1..8]of integer;
  rc:array[1..8,1..3]of integer;
  t,i,j:longint;
begin
  t:=0;
  for i:=1 to 7 do
  begin
    readln(rc[i,1],rc[i,2]);
    b[i]:=rc[i,1]+rc[i,2];
    if (b[i]>8)and(b[i]>t)then t:=b[i];
  end;
  if t=0 then writeln(0)
  else for i:=1 to 7 do if b[i]=t then 
  begin
    writeln(i);
    break;
  end;
end.
