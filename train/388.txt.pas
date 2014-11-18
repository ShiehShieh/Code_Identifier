var
  n,m,i,j,i1,j1,q1,q2,tmpint:integer;
  tmp:array[1..10]of integer;
  list:array[1..30000,1..10]of ^integer;
  b:array[1..30000]of ^integer;
  a:array[1..100,1..10]of integer;
  boo1,boo2:boolean;
begin
  readln(n);
  readln(m);
  for i:=1 to m do
    for j:=1 to n do read(a[i,j]);
  for i:=1 to n do begin
    new(list[1,i]);
    list[1,i]^:=-1;
  end;
  q1:=1;q2:=1;
  new(b[1]);
  b[1]^:=0;
  while q1<=q2 do begin
    if b[q1]^>m then begin
      writeln('The patient will be dead.');
      halt;
    end;
    for i:=1 to m do begin
      for j:=1 to n do tmp[j]:=list[q1,j]^;
      for J:=1 to n do begin
        tmpint:=tmp[j]+a[i,j];
        if tmpint<0 then tmp[j]:=-1;
        if tmpint>0 then tmp[j]:=0;
        if tmpint=0 then tmp[j]:=0;
      end;
      boo2:=true;
      for i1:=1 to q2 do begin
        boo1:=false;
        for j1:=1 to n do if list[i1,j1]^<>tmp[j1] then begin
          boo1:=true;
          break;
        end;
        boo2:=boo2 and boo1;
        if not boo2 then break;
      end;
      if boo2 then begin
        inc(q2);
        for j:=1 to n do begin
          new(list[q2,j]);
          list[q2,j]^:=tmp[j];
          new(b[q2]);
          b[q2]^:=b[q1]^+1;
        end;
        boo1:=true;
        for j:=1 to n do if tmp[j]<>0 then begin
          boo1:=false;
          break;
        end;
        if boo1 then begin
          writeln(b[q2]^);
          halt;
        end;
      end;
    end;
    inc(q1);
  end;
  writeln('The patient will be dead.');
end.
