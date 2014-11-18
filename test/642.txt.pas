var
        s,q,w,n,m:int64;
        i:longint;
        p,a:array[0..400005] of int64;
procedure max(t,x,y:int64);
  var
        m:int64;
        i:longint;
  begin
        m:=(x+y) div 2;
        if x>=y then begin if x=y then p[t]:=a[x];exit;end;
        p[t]:=-9223372036854775808;
        for i:=x to y do
                if a[i]>p[t] then p[t]:=a[i];
        max(t*2,x,m);max(t*2+1,m+1,y);
  end;
procedure zout(t,x,y:int64);
  var
        i:longint;
        m:int64;
  begin
        m:=(x+y) div 2;
        if (x>=w) and (q>=y) then begin
                if p[t]>s then s:=p[t];
        end else begin
                if x<y then begin
                        if not(w>m) then zout(t*2,x,m);
                        if not(q<m+1) then zout(t*2+1,m+1,y);
                end;
        end;
  end;
begin
        readln(n);
        for i:=1 to n do
                read(a[i]);
        max(1,1,n);
        readln(m);
        for i:=1 to m do begin
                readln(w,q);
                s:=-9223372036854775808;
                zout(1,1,n);
                write(s);
        end;


end.
