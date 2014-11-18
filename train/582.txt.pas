program tc;
var
  p, l, b : longint;
  t : 0..9;
  x, z : array[1..10000] of 0..9;

  procedure bnm(y:longint);
  var
    i, j, d : longint;
  begin
    if y=1 then x[1]:=2
    else
    begin
      bnm(y div 2);
      for i:=1 to b do
      begin
        t:=0;
        for j:=1 to b do
        begin
          d := z[i+j-1]+t+x[i]*x[j];
          z[i+j-1] := d mod 10;
          t := d div 10;
        end;
        if t>0 then z[i+j]:=t;
      end;
      if t=0 then b:=b+b-1 else b:=b+b;
      t:=0;
      if y mod 2=1 then
      begin
      for i := 1 to b do
      begin
        d := z[i]*2+t;
        z[i] := d mod 10;
        t:= d div 10;
      end;
      if t<>0 then begin b:=b+1; z[b] := 1; end;
      end;
       if b>500 then b:=500;
      for i := 1 to b do begin x[i]:=z[i]; z[i]:=0; end;
    end;
  end;
begin
  readln(p);
  t:=0;
  b:=1;
  for l:=1 to 500 do z[l]:=0;
  x[1]:=1;
  bnm(p);
  writeln(trunc(p*(ln(2)/ln(10))+1));
  b:=0;
  for l:=500 downto 2 do
  begin
  b:=b+1;
  write(x[l]);
  if b mod 50 =0 then writeln;
  end;
  write(x[1]-1);
end.                 
