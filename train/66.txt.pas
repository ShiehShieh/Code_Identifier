var
        p,n,t,k,x,y,x1,x2,y1,y2:longint;
        v:array[0..1025,0..1025] of longint;
  function lowbit(x:longint):longint;
        begin
                lowbit:=x and (-x);
        end;
  function sum(x,y:longint):longint;
        var
                t:longint;
        begin
                sum:=0;
                while x>0 do begin
                        t:=y;
                        while t>0 do begin
                        sum:=sum+v[x,t];
                        t:=t-lowbit(t);
                        end;
                        x:=x-lowbit(x);
                end;
        end;
begin
        readln(n);
        n:=n+1;
        read(k);
        while k<>3 do begin
                if k=1 then begin
                        readln(x,y,p);
                        x:=x+1;y:=y+1;
                        while (x>0) and (x<=n) do begin
                                t:=y;
                                while (t>0) and (t<=n) do begin
                                        v[x,t]:=v[x,t]+p;
                                        t:=t+lowbit(t);
                                end;
                                x:=x+lowbit(x);
                        end;
                end;
                if k=2 then begin
                        readln(x1,y1,x2,y2);
                        inc(x2);inc(y2);
                        writeln(sum(x2,y2)-sum(x1,y2)-sum(x2,y1)+sum(x1,y1));
                end;
                read(k);
        end;
end.
