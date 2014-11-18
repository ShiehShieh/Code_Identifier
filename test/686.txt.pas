var n,ans:longint;
procedure search(x:longint);
var i:longint;
begin
    inc(ans);
    for i:=1 to x div 2 do
       search(i); 
end;
begin
    read(n);
    ans:=0;
    search(n);
    writeln(ans);
end.
