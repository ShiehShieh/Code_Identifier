program P1484;
  var
    i,j,m:longint;
    a:array [1..20] of integer;
    s:string;f:char;
  begin
    readln(s);
    j:=1;
    for i:=1 to 13 do
      if s[i]<>'-' then
        begin
          a[j]:=ord(s[i])-48;
          j:=j+1;
        end;
    m:=0;
    for i:=1 to 9 do m:=m+a[i]*i;
    m:=m mod 11;
    if m=10 then f:='X' else f:=chr(m+48);
    if f=s[13] then writeln('Right') else begin s[13]:=f; writeln(s); end;
  end.

