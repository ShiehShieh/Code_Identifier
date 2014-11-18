program Dzs;
var a,b,c,d,i,j,m,n,k:longint;
    e:array[0..40000]of boolean;
    q:array[0..40000,0..101]of boolean;
    w:array[1..200]of longint;
begin
     readln(n);
     a:=n div 2;
     for i:=1 to n do
     begin
          readln(w[i]);
          inc(m,w[i]);
    end;
    b:=m div 2;
    q[0,0]:=true;e[0]:=true;
    for i:=1 to n do
        for j:=b-w[i] downto 0 do
        if e[j] then
        begin
             c:=j+w[i];
             e[c]:=true;
             for k:=a downto 0 do
             if q[j,k] then q[c,k+1]:=true;
        end;
    if n mod 2=0 then c:=a
      else c:=a+1;
    while (not e[b])or(not q[b,a])and(not q[b,c]) do dec(b);
    writeln(b,' ',m-b);
end.

