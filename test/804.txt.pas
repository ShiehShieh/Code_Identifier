program P1059;
var
        min,aa          :longint;
        tell            :boolean;
        n,i,j,k,sum     :longint;
        ans             :array[1..100,0..10000]of boolean;
        num             :array[1..100,0..100]of longint;
begin
                readln(n); aa:=maxlongint; min:=0;
        for i:=1 to n do
        begin
                sum:=0; read(k); j:=0;
                while k<>-1 do
                begin
                        inc(j); num[i,j]:=k; sum:=sum+k; read(k);
                end;
                num[i,0]:=j; if aa>sum then aa:=sum;
        end;
        fillchar(ans,sizeof(ans),false);
        for i:=1 to n do
        begin
                ans[i,0]:=true;
                for j:=1 to num[i,0] do
                begin
                        for k:=aa downto num[i,j] do
                        if ans[i,k-num[i,j]] then ans[i,k]:=true;
                end;
        end;
        tell:=true;
        for i:=aa downto 0 do
        begin
                for j:=1 to n do
                if ans[j,i]=false then break;
                if ans[j,i] then break;
        end;
        writeln(i);
       end.

