var
                s,n,i,j:                longint;
                f:                      array[0..20000] of boolean;
                v :                     array[1..30] of longint;
begin
                readln(s);
                readln(n);
                for i:=1 to n do
                readln(v[i]);
                fillchar(f,sizeof(f),false);
                f[0]:=true;
                for i:=1 to n do
                 for j:=s downto v[i] do
                 if f[j-v[i]] then f[j]:=true;
                for i:=s downto 0 do
                if f[i] then begin writeln(s-i);halt;end;
end.
