var i,n,j,t:longint;
begin
  readln(n);
  for i:=1 to 20000 do begin
    t:=0;
    for j:=1 to trunc(sqrt(i)) do if i mod j=0 then inc(t);
    t:=t*2;
    if sqrt(i)=trunc(sqrt(i)) then t:=t-1;
    if t=n then begin
      writeln(i);
      exit;
    end;
  end;
  writeln('NO SOLUTION');
end.
