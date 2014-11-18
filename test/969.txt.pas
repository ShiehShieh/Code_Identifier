program expand;
var a,b:ansistring;
p1,p2,i,p3,v:longint;
x,p:int64;
j:char;
begin
read(p1,p2);
readln(p3);
readln(a);
b:=a;
for i:=1 to length(a) do
 if a[i]='-' then
  if (ord(a[i-1])<ord(a[i+1]))then
   if (((ord(a[i-1])>=48)and(ord(a[i+1])>=48)and(ord(a[i-1])<=57)and(ord(a[i+1])<=57)))
     or (((ord(a[i-1])>=97)and(ord(a[i+1])>=97)and(ord(a[i-1])<=122)and(ord(a[i+1])<=122)))
     then begin
     if p3=1 then begin
        if p1=1 then for j:=chr(ord(a[i-1])+1) to chr(ord(a[i+1])-1) do
          for v:=1 to p2 do  begin p:=1; b[x+p]:=j; x:=x+p;
           end;
        if p1=2 then if (((ord(a[i-1])>=97)and(ord(a[i+1])>=97)and(ord(a[i-1])<=122)and(ord(a[i+1])<=122)))
          then for j:=chr(ord(a[i-1])+1) to chr(ord(a[i+1])-1) do
           for v:=1 to p2 do begin p:=1; b[x+p]:=chr(ord(j)-32);
             x:=x+p; end else
             for j:=chr(ord(a[i-1])+1) to chr(ord(a[i+1])-1) do
          for v:=1 to p2 do  begin p:=1; b[x+p]:=j; x:=x+p;
           end;
        if p1=3 then for j:=chr(ord(a[i-1])+1) to chr(ord(a[i+1])-1) do
           for v:=1 to p2 do begin p:=1; b[x+p]:='*'; x:=x+p; end
          end;
     if p3=2 then begin
         if p1=1 then for j:=chr(ord(a[i+1])-1) downto chr(ord(a[i-1])+1) do
          for v:=1 to p2 do begin
            p:=1; b[x+p]:=j; x:=x+p;
           end;
          if p1=2 then if (((ord(a[i-1])>=97)and(ord(a[i+1])>=97)and(ord(a[i-1])<=122)and(ord(a[i+1])<=122)))
         then for j:=chr(ord(a[i+1])-1) downto chr(ord(a[i-1])+1) do
           for v:=1 to p2 do begin p:=1; b[x+p]:=chr(ord(j)-32);
             x:=x+p;
            end else for j:=chr(ord(a[i-1])+1) to chr(ord(a[i+1])-1) do
          for v:=1 to p2 do  begin p:=1; b[x+p]:=j; x:=x+p;
           end;
          if p1=3 then  for j:=chr(ord(a[i+1])-1) downto chr(ord(a[i-1])+1) do
           for v:=1 to p2 do begin p:=1;  b[x+p]:='*'; x:=x+p;
            end
          end
         end
  else begin inc(x); b[x]:=a[i] end
 else begin inc(x); b[x]:=a[i] end
 else begin inc(x); b[x]:=a[i] end;
for i:=1 to x do
 write(b[i]);
readln;
end.
