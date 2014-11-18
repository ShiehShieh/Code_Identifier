var
  a,yw:array[1..300] of integer;
  i,n,max,m,sx,yy,k:integer;
begin
  read(n);
  for i:=1 to n do
    begin
      read(yw[i],sx,yy);
      a[i]:=yw[i]+sx+yy;
    end;
  k:=1;
  while k<=5 do
    begin
      max:=0;
      for i:=1 to n do
        if max<a[i]
          then begin
                 max:=a[i];
                 m:=i;
               end
          else
            if max=a[i]
              then
                if yw[m]<yw[i]
                  then m:=i;
      writeln(m,' ',a[m]);
      a[m]:=0;
      inc(k);
    end;
end.
