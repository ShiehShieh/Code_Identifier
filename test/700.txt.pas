var
  n,k,i:longint;
  sn:real;
begin
  readln(k);
  sn:=0;
  i:=0;
  while sn<=k do
  begin
    inc(i);
    sn:=sn+1/i;
  end;
  writeln(i);
end.
