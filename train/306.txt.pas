program p1105;
var n,p,i,j,k,l:integer;
    c,u:array[1..200]of longint;
    f:array[1..200]of boolean;
    w:array[1..200,1..200]of longint;
    y:boolean;
begin
    readln(n,p);
    fillchar(f,sizeof(f),false);
    for i:=1 to n do
    readln(c[i],u[i]);
    for k:=1 to p do
    begin
    read(i,j);
    readln(w[i,j]);
    f[i]:=true;
    end;
    for i:=n downto 1 do
    if c[i]<>0 then break;
    l:=i+1;
    for i:=l to n do
     begin
     for j:=1 to i do
     if c[j]<>0 then
     c[i]:=c[i]+w[j,i]*c[j];
     c[i]:=c[i]-u[i];
     if c[i]<0 then c[i]:=0;
     end;
    for i:=1 to n do
    if (not f[i])and(c[i]>0) then
    begin
    writeln(i,' ',c[i]);
    y:=true;
    end;
    if not y then
    writeln('NULL');
end.
