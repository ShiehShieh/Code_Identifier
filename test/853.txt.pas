var     m,n,i,x1,x2,y1,y2,tot,k,x0,y0,sum:longint;
        f,x,y:array[1..100000] of longint;
begin
        readln(n);
        read(m);
        while m <> 3 do
        begin
          if m=1 then
          begin
            read(x0,y0,k);
            inc(tot);
            f[tot]:=k;
            x[tot]:=x0;
            y[tot]:=y0;
          end;
          if m=2 then
          begin
            sum:=0;
            read(x1,y1,x2,y2);
            for i:=1 to tot do
            begin
              if (x[i]>=x1)and(x[i]<=x2)and(y[i]>=y1)and(y[i]<=y2) then
              sum:=sum+f[i];
            end;
            writeln(sum);
          end;
          read(m);
        end;
end.
