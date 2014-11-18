program expand;
var i,j,k,p1,p2,p3:longint;
s,ss:ansistring;
begin
readln(p1,p2,p3);
readln(s);
ss:=ss+s[1];
for i:=2 to length(s)-1 do
if s[i]='-' then begin
if ((((ord(s[i-1]))>=ord('0')) and (ord(s[i+1])<=ord('9'))) or ((ord(s[i-1])>=ord('a')) and (ord(s[i+1])<=ord('z')))) and (ord(s[i-1])<ord(s[i+1])) then begin
if p3=1 then begin
if (ord(s[i-1])>=ord('a')) and (ord(s[i+1])<=ord('z')) then begin
if p1=1 then
for j:=ord(s[i-1])+1 to ord(s[i+1])-1 do
for k:=1 to p2 do
ss:=ss+chr(ord(j));
if p1=2 then
for j:=ord(s[i-1])+1 to ord(s[i+1])-1 do
for k:=1 to p2 do
ss:=ss+chr(ord(j)+ord('A')-ord('a'));
end else if p1<>3 then
for j:=ord(s[i-1])+1 to ord(s[i+1])-1 do
for k:=1 to p2 do
ss:=ss+chr(ord(j));
if p1=3 then
for j:=ord(s[i-1])+1 to ord(s[i+1])-1 do
for k:=1 to p2 do
ss:=ss+'*';
end;
if p3=2 then begin
if (ord(s[i-1])>=ord('a')) and (ord(s[i+1])<=ord('z')) then begin
if p1=1 then
for j:=ord(s[i+1])-1 downto ord(s[i-1])+1 do
for k:=1 to p2 do
ss:=ss+chr(ord(j));
if p1=2 then
for j:=ord(s[i+1])-1 downto ord(s[i-1])+1 do
for k:=1 to p2 do
ss:=ss+chr(ord(j)+ord('A')-ord('a'));
end else if p1<>3 then
for j:=ord(s[i-1])+1 to ord(s[i+1])-1 do
for k:=1 to p2 do
ss:=ss+chr(ord(j));
if p1=3 then
for j:=ord(s[i-1])+1 to ord(s[i+1])-1 do
for k:=1 to p2 do
ss:=ss+'*';
end;
end else ss:=ss+s[i];
end else ss:=ss+s[i];
ss:=ss+s[length(s)];
writeln(ss);
end.
