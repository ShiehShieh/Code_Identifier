
program scholar;
var
n,i,j,a,b:integer;
c,t,num:array[1..500]of integer;
procedure swap;
var tmp:integer;
begin
tmp:=num[i];num[i]:=num[j];num[j]:=tmp;
tmp:=t[i];t[i]:=t[j];t[j]:=tmp;
tmp:=c[i];c[i]:=c[j];c[j]:=tmp;
end;
begin
readln(n);
for i:=1 to n do
begin
    read(c[i],a,b);
    t[i]:=c[i]+a+b;
    num[i]:=i;
end;
for i:=1 to 5 do
for j:=n downto i+1 do
begin

    if t[i]<t[j]then begin swap;continue;end;
    if (t[i]=t[j])and(c[i]<c[j])then begin swap;continue;end;
    if (t[i]=t[j])and(c[i]=c[j])and(num[i]>num[j])then begin swap;continue;end;
end;
for i:=1 to 5 do writeln(num[i],' ',t[i]);
end.

   end;
   for i:= 1 to n do
   begin
     for j:= 1 to n do
       begin
         if  d[i]=e[j] then e[j]:=i;
       end;
     end;
   for i:= 1 to 5 do
   begin
    write(e[i],' ',d[i]);
    writeln;
   end;
end.
