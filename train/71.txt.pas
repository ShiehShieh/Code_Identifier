var
    s,s1,s2,n:integer;
    t:longint;
procedure dg(dep:integer);
begin
    if dep=n*2 then begin
        inc(t);
      //  writeln;
        end
    else begin
        if(s-1>=0)and(s2+1<=n) then begin
            s:=s-1;
            s2:=s2+1;
           // write(0);
            dg(dep+1);
            inc(s);
            dec(s2);
        end;
        if(s+1<=n)and(s1+1<=n) then begin
            inc(s);
            s1:=s1+1;
           // write(1);
            dg(dep+1);
            dec(s);
            dec(s1);
        end;
    end;
end;
begin
    readln(n);
    //write(1);
    s:=1; s1:=1;
    dg(1);
    writeln(t);
end.
