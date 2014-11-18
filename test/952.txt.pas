program p1318;
var
s ,t ,w ,i ,j ,k   :longint;
st:string;
begin
readln(s ,t ,w);
readln(st);
for k:=1 to 5 do
for i:=w downto 1 do
if ord(st[i])+(w-i)<t+ord('a')-1 then
begin
st[i]:=chr(ord(st[i])+1);
for j:=i+1 to w do
st[j]:=chr(ord(st[j-1])+1);
writeln(st);
break;
end;
end. 

