var
        a,c,d:array[1..100] of integer;
        b:array[1..10,1..100] of longint;
        round:array[1..100,0..100] of integer;
        bo:array[1..100] of boolean;
        n,m,k:longint;

procedure prepare(var t:longint);
var
        i,j:longint;
begin
        fillchar(bo,sizeof(bo),0);
        for i:=1 to n do
            if not bo[i] then begin
               inc(t);
               j:=i;
               inc(round[t,0]);
               while c[j]<>i do begin
                  round[t,round[t,0]]:=c[j];
                  bo[j]:=true;
                  inc(round[t,0]);
                  j:=c[j];
               end;
               round[t,round[t,0]]:=c[j];
               bo[j]:=true;
            end;
end;

procedure work(t:longint);
var
        i,j,p,l,f:longint;
begin
        j:=k div m;
        for i:=1 to t do begin
            for p:=1 to round[i,0] do begin
                f:=(j mod round[i,0]+p-1) mod round[i,0]+1;
                a[round[i,p]]:=round[i,f];
            end;
        end;
end;


procedure main;
var
        i,j,gs:longint;
begin
        readln(n,m,k);
        for i:=1 to n do begin
            a[i]:=i;
            c[i]:=i;
        end;
        for i:=1 to m do begin
            gs:=0;
            for j:=1 to n do begin
                read(b[i,j]);
                d[j]:=c[b[i,j]];
            end;
            c:=d;
        end;
        prepare(gs);
        work(gs);
        for i:=1 to k mod m do begin
            for j:=1 to n do
                d[j]:=a[b[i,j]];
            a:=d;
        end;
        for i:=1 to n do begin
            write(a[i]);
            if i<>n then write(' ')
            else
               writeln;
        end;
end;

begin
           main;
end.
