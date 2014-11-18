program asdf;
  var
    s:array[1..1000] of string;
    a:array['a'..'z'] of integer;
    i,j,n,t:integer;
    c:char;
    s1:string;
  function bijiao(s1,s2:string):boolean;
  var
    i:integer;
  begin
    i:=0;
    while (i<length(s1))and(i<length(s2)) do
      begin
        inc(i);
        if a[(s1[i])]>a[(s2[i])] then exit(true)
        else if a[(s1[i])]<a[(s2[i])] then exit(false);
      end;
    if length(s1)>length(s2) then exit(true)
    else exit(false);
  end;
  begin
    for i:=1 to 26 do begin read(c);a[c]:=i;end;
    readln(n);
    for i:=1 to n do readln(s[i]);
    readln(t);
    for i:=1 to n-1 do
      for j:=i+1 to n do
        begin
          if bijiao(s[i],s[j]) then
            begin
              s1:=s[i];s[i]:=s[j];s[j]:=s1;
            end;
        end;
    if t=1 then
      for i:=1 to n do writeln(s[i])
    else for i:=n downto 1 do writeln(s[i]);
  end.
