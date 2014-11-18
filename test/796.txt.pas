program    P1364;
var
        m,n,i,j,max     :longint;
        t1,t2,t3        :longint;
        map             :array[0..200,0..200]of longint;
        mark            :array[0..200,0..200]of boolean;
        ans             :array[0..200,0..200]of longint;
begin
        readln(m,n);
        for i:=1 to m do
        for j:=1 to n do read(map[i,j]);
        fillchar(mark,sizeof(mark),false);
        ans[m,n div 2]:=map[m,n div 2]; mark[m,n div 2]:=true;
        ans[m,n div 2+1]:=map[m,n div 2+1]; mark[m,n div 2+1]:=true;
        ans[m,n div 2+2]:=map[m,n div 2+2]; mark[m,n div 2+2]:=true;
        for i:=m downto 1 do
        for j:=1 to n do
        if mark[i,j] then
        begin
                t1:=ans[i,j]+map[i-1,j];
                if (ans[i-1,j]<t1) then
                begin ans[i-1,j]:=t1; mark[i-1,j]:=true; end;
                if j<>1 then t2:=ans[i,j]+map[i-1,j-1];
                if ans[i-1,j-1]<t2 then
                begin ans[i-1,j-1]:=t2; mark[i-1,j-1]:=true; end;
                if j<>n then t3:=ans[i,j]+map[i-1,j+1];
                if ans[i-1,j+1]<t3 then
                begin ans[i-1,j+1]:=t3; mark[i-1,j+1]:=true; end;
        end;
        max:=0;
        for i:=1 to n do
        if ans[1,i]>max then max:=ans[1,i];
        writeln(max);
        
end.

