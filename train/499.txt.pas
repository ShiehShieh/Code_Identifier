var
                        n,i,j,tottime:          longint;
                        f:              array[0..1000] of longint;
                        p,time:            array[1..100] of longint;
begin
                        readln(n);
                        readln(tottime);
                        for i:=1 to n do
                        readln(p[i],time[i]);
                        for i:=1 to n do
                        for j:=tottime downto time[i] do begin
                                 if f[j-time[i]]+p[i]>f[j] then
                                 f[j]:=f[j-time[i]]+p[i];
                        end;
                        writeln(f[tottime]);

end.
