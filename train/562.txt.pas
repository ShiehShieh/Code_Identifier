var
        a:array[0..100000] of char;
        s,v:array[0..100000] of longint;
        vs,tm,n,i,j,k,t,x,y,l:longint;
        tf:char;
        fl:boolean;
function n2c(n:longint):longint;
  var t,i:longint;
  begin
        t:=1;
        for i:=1 to n do
                t:=t*2;
        n2c:=t;
  end;
begin
        readln(n);
        readln(y,x);
        if y>15 then y:=15;
        l:=n2c(n);
        for i:=1 to l do read(a[i]);
        for j:=1 to l do v[i]:=0;
        v[l]:=1;v[0]:=1;
        for i:=0 to n do begin
                s[i]:=0;
                tf:=a[1];fl:=true;
                for j:=1 to l do begin
                        if v[j]=1 then begin
                                if tf<>a[j] then fl:=false;
                                if fl then begin
                                        if tf='0' then s[i]:=s[i]+5;
                                        if tf='1' then s[i]:=s[i]+2;
                                        tf:=a[j+1];
                                        fl:=true;
                                end;
                                if not fl then begin
                                        s[i]:=s[i]+1;
                                        tf:=a[j+1];
                                        fl:=true;
                                end;

                        end else begin
                                if tf<>a[j] then fl:=false;
                        end;
                end;
                tm:=0;
                for k:=1 to l do begin
                        if v[k]=1 then begin
                                v[(k+tm) div 2]:=1;
                                tm:=k;
                        end;
                end;
        end;
        for i:=n+1 to 10000 do s[i]:=s[i-1];
        vs:=0;
        for i:=x to y do vs:=vs+s[n-i];
        writeln(vs);

end.
