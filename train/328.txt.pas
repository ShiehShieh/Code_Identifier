program p1153;
  var
    a:array[0..200] of integer;
    f:array[0..200,0..8000] of boolean;
    n,i,j,k,s:longint;
  begin
    read(n);
    for i:=1 to n do
     begin
     read(a[i]);
     inc(s,a[i]);
     end;
    f[0,0]:=true;
    for i:=1 to n do
      for j:=n div 2 downto 0 do
        for k:=j*40 downto 0 do
         if f[j,k] then
          f[j+1,k+a[i]]:=true;
    for i:=s div 2 downto 0 do
      if f[n div 2,i] then
       begin
         writeln(i,' ',s-i);
         exit;
       end;
  end.

