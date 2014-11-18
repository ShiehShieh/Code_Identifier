var
        n,p,i,j,k,min:integer;
        t,l,r:array[1..100]of integer;

function max(a,b:integer):integer;
        begin
                if a>b then max:=a else max:=b;
        end;
begin
        read(n);
        for i:=1 to n do begin
                read(t[i]);
                l[i]:=1;
                r[i]:=1;
        end;
        for i:=2 to n do
                for j:=1 to i-1 do
                        if t[i]>t[j]then l[i]:=max(l[i],l[j]+1);
        for i:=n-1 downto 1 do
                for j:=n downto i+1 do
                        if t[i]>t[j]then r[i]:=max(r[i],r[j]+1);
        min:=maxint;
        for i:=1 to n do begin
                k:=n-l[i]-r[i]+1;
                if min>k then min:=k;
        end;
        writeln(min);
end.
