program hechangduixing;
      var a,f,g:array[1..300] of longint;
            n,i,j:longint;
            max:int64;
      begin
          readln(n);
        for i:=1 to n do
          read(a[i]);
       for i:=1 to n do
          begin
            f[i]:=1;
           g[i]:=1;
        end;
      for i:=1 to n do
         begin
            for j:=1 to i-1 do
                 if (a[j]<a[i])and(f[j]+1>f[i]) then f[i]:=f[j]+1;
        end;
      for i:=n downto 1 do
         begin
             for j:=n downto i+1 do
                 if (a[j]<a[i])and(g[j]+1>g[i]) then g[i]:=g[j]+1;
                 end;
     max:=-maxint;
      for i:=1 to n do
          if f[i]+g[i]-1>max then max:=f[i]+g[i]-1;
          writeln(n-max);
 end.
