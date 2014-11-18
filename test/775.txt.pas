var
                i,j,n,max,k:          longint;
                a:              array[1..100] of longint;
                f1,f2:          array[1..100] of longint;
begin
                readln(n);
                for i:=1 to n do
                read(a[i]);
                f1[1]:=1;
                for i:=2 to n do begin
                        max:=0;
                        for j:=1 to i-1 do begin
                        if a[j]<a[i] then if f1[j]>max then max:=f1[j];
                        f1[i]:=max+1;
                        end;
                end;
                for i:=1 to n div 2 do begin
                        k:=a[i];
                        a[i]:=a[n-i+1];
                        a[n-i+1]:=k;
                end;
                f2[1]:=1;
                for i:=2 to n do begin
                        max:=0;
                        for j:=1 to i-1 do begin
                        if a[j]<a[i] then if f2[j]>max then max:=f2[j];
                        f2[i]:=max+1;
                        end;
                end;
                max:=-maxlongint;
                for i:=1 to n do begin
                        if f1[i]+f2[n-i+1]>max then max:=f1[i]+f2[n-i+1];
                end;
                writeln(n-max+1);
end.
