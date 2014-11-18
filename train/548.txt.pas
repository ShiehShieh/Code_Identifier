program P1364;
var
        mark            :array[1..200,1..200]of boolean;
        map             :array[1..200,1..200]of longint;
        ans             :array[1..200,1..200]of longint;
        n,m,i,j,k,p     :longint;
        max,t1,t2,t3    :longint;
procedure  work;
begin
        for i:=1 to n do for j:=1 to m do read(map[i,j]);
        fillchar(ans,sizeof(ans),0);
        fillchar(mark,sizeof(mark),false);
        ans[n,p]:=map[n,p]; mark[n,p]:=true;
        ans[n,p+1]:=map[n,p+1]; mark[n,p+1]:=true;
        ans[n,p-1]:=map[n,p-1]; mark[n,p-1]:=true;
        for i:=n-1 downto 1 do
        for j:=1 to m do
        if mark[i+1,j] then
        begin
                t1:=-maxlongint; t2:=-maxlongint; t3:=-maxlongint;
                t1:=ans[i+1,j]+map[i,j]; if ans[i,j]<t1 then begin mark[i,j]:=true; ans[i,j]:=t1; end;
                if j<>m then
                begin
                        t2:=ans[i+1,j]+map[i,j+1];
                        if ans[i,j+1]<t2 then begin mark[i,j+1]:=true; ans[i,j+1]:=t2; end;
                end;
                if j<>1 then
                begin
                        t3:=ans[i+1,j]+map[i,j-1];
                        if ans[i,j-1]<t3 then begin mark[i,j-1]:=true; ans[i,j-1]:=t3; end;
                end;
        end;
end;
begin
               readln(n,m); p:=m div 2+1;
        work;
        max:=-maxlongint;
        for i:=1 to n do
        for j:=1 to m do
        if ans[i,j]>max then max:=ans[i,j];
        if max<0 then max:=0;
        writeln(max);
        end.

