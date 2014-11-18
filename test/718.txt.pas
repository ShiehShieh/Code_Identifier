var ss,tt,st:string;
a,b,c:array[1..1000] of integer;
i:integer;f,fs,ft:boolean;
procedure print;
var j:longint;
begin
  i:=i-1;
  for j:=i downto 1 do begin
    write(c[j]);
    if ((j-1) mod 3=0) and (j<>1) then write(',');
  end;
  writeln;
  halt;
end;
procedure add;
begin
  for i:=1 to length(ss) do
    a[i]:=ord(ss[length(ss)-i+1])-48;
  for i:=1 to length(tt) do
    b[i]:=ord(tt[length(tt)-i+1])-48;
  i:=1;f:=false;
  repeat
    c[i]:=a[i]+b[i];
    if f then begin c[i]:=c[i]+1; f:=false; end;
    if c[i]>=10 then begin c[i]:=c[i]-10; f:=true; end;
    i:=i+1;
  until (i>length(ss)) and (i>length(tt));
  if f then begin i:=i+1; c[i-1]:=1; end;
  if fs=false then write('-');
  print;
end;
procedure check;
begin
  for i:=length(ss) downto 1 do
    if ss[i]<tt[i] then begin write('-');st:=ss; ss:=tt; tt:=st; exit; end
    else if ss[i]>tt[i] then exit;
  writeln('0');
  halt;
end;
procedure sub;
begin
  if length(ss)<length(tt) then begin write('-');st:=ss; ss:=tt; tt:=st;end
  else if length(ss)=length(tt) then check;
  for i:=1 to length(ss) do
    a[i]:=ord(ss[length(ss)-i+1])-48;
  for i:=1 to length(tt) do
    b[i]:=ord(tt[length(tt)-i+1])-48;
  i:=1;f:=false;
  repeat
    if a[i]<b[i] then begin a[i+1]:=a[i+1]-1; a[i]:=a[i]+10; end;
    c[i]:=a[i]-b[i];
    i:=i+1;
  until (i>length(ss)) and (i>length(tt));
  print;
end;
begin
  readln(st);
  for i:=1 to length(st) do
    if st[i]=' ' then break;
  ss:=copy(st,1,i-1);
  tt:=copy(st,i+1,length(st)-i);
  fs:=true;ft:=true;
  if ss[1]='-' then begin fs:=false; delete(ss,1,1); end;
  if tt[1]='-' then begin ft:=false; delete(tt,1,1); end;
  if ord(fs)+ord(ft)=1 then add
  else if ord(fs)+ord(ft)=0 then begin st:=ss; ss:=tt; tt:=st; sub; end
  else sub;
end.

