Program ex1;
Var
a,b,c:packed array[1..7] of integer;
i,j,n,m:integer;
Begin
        for i:=1 to 7 do
        begin
        read(a[i]);
        read(b[i]);
        c[i]:=a[i]+b[i];
        end;
                for m:=1 to 6 do
                begin
                for i:=1 to 7-m do
                begin
                if c[i]<c[i+1] then
                begin
                n:=c[i];
                c[i]:=c[i+1];
                c[i+1]:=n;
                end;
                end;
                end;
        if c[1]<8 then
        writeln('0')
        else
        begin
        m:=1;
        while a[m]+b[m]<>c[1] do
        begin
        m:=m+1;
        end;
        writeln(m);
        end;
end.

