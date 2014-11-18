var a:array[1..11] of longint;
    i,j,k,l,m:longint;
begin
  readln(i,j);
  l:=0;
  while j<>0 do
    begin
      inc(l);
      a[l]:=j mod 2;
      j:=j div 2;
    end;
  k:=1;
  for j:=1 to l do
    begin
      if a[j]=1 then inc(m,k);
      k:=k*i;
    end;
  write(m);
end.

