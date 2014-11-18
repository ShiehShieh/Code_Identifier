var n,m,d,i,j,t:longint;
    c:array[1..120]of longint;
    a:array[1..1000]of boolean;
begin
  readln(n);
  fillchar(a,sizeof(a),false);
  d:=0;
  for i:=1 to n do
  begin
    read(m);
    if not a[m] then begin
      a[m]:=true;
       inc(d);
      c[d]:=m;
    end;
  end;
  for i:=d downto 2 do
    for j:=1 to i-1 do begin
      if c[j]>c[j+1] then begin
        t:=c[j]; c[j]:=c[j+1]; c[j+1]:=t;
      end;
    end;

  writeln(d);
  for i:=1 to d do write(c[i],' ');
  writeln;

end.
