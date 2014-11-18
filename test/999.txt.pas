var
 n,t,i,j:integer;
 wor:array [1..1000] of string;
 dic,temp:string;
function biggerstr(a,b:string):boolean;
 function biggercha(a,b:char):boolean;
begin
  if pos(a,dic)>pos(b,dic) then biggercha:=true else biggercha:=false;
end;
 var
i:integer;
 begin
i:=0;
repeat
  i:=i+1;
until (a[i]<>b[i]) or (i=length(a)) or (i=length(b));
if i=length(a) then biggerstr:=false;
if i=length(b) then biggerstr:=true;
if a[i]<>b[i] then biggerstr:=biggercha(a[i],b[i]);
 end;
begin
 randomize;
 readln(dic);
 readln(n);
 for i:=1 to n do readln(wor[i]);
 readln(t);
 for i:=1 to n do for j:=i+1 to n do if biggerstr(wor[i],wor[j]) then
begin
  temp:=wor[i];
  wor[i]:=wor[j];
  wor[j]:=temp;
end;
 if t=0 then for i:=n downto 1 do writeln(wor[i]);
 if t=1 then for i:=1 to n do writeln(wor[i]);
end.

