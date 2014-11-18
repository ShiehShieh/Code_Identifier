var a:longint;
s:array[1..100000] of integer;
i,p,j:longint;
begin
read(a);
if a=0 then write(0) else if a=1 then write(1) else if a=2 then write(2) else if a=3 then write(3) else begin
if a mod 3=1 then begin
s[1]:=4;
a:=a-4;
end else if a mod 3=2 then begin
s[1]:=2;
a:=a-2;
end else s[1]:=1;
a:=a div 3;
p:=1;
for i:=1 to a do begin
for j:=1 to p do s[j]:=s[j]*3;
for j:=1 to p do if s[j]>9 then begin
if j=p then p:=p+1;
s[j+1]:=s[j+1]+s[j] div 10;
s[j]:=s[j] mod 10;
end;
end;
for i:=p downto 1 do begin
write(s[i]);
end;
end;
end.
