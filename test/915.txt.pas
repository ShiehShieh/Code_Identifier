program dele;
var
a,b:string;
n,c,d,e,f,g,h:longint;
k:longint;
function clear(d:string):string;
begin
while (length(d)>0) and ((d[1]='0') or (d[1]=' ')) do
delete(d,1,1);
if d='' then d:='0';
clear:=d;
end;
begin
readln(a);
readln(n);
f:=length(a)-1;
for e:=1 to n do begin
k:=0; d:=0;
while k<>1 do begin
 inc(d); if a[d]>a[d+1] then begin k:=1; delete(a,d,1); end;
 if (d=length(a)-1) and (k<>1) then begin k:=1; delete(a,d+1,1); end;
end;
end;
b:=clear(a);
writeln(b);
end.

