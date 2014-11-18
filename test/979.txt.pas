var
i,j,k,n,m,o,rp:longint;
s,c,ss:ansistring;
begin
readln(n,m,k);
readln(s);
i:=0;
while i<length(s) do
begin
inc(i);
if (s[i]='-')
then if ( (s[i-1]<='z')and(s[i-1]>='a')and(s[i+1]<='z')and(s[i+1]>='a')and(s[i+1]>s[i-1]))or((s

[i-1]<='9')and(s[i-1]>='0')and(s[i+1]<='9')and(s[i+1]>='0')and(s[i+1]>s[i-1]))
then begin
c:='';
for j:=ord(s[i-1])+1 to ord(s[i+1])-1 do
c:=c+chr(j);
if (n=2)and(s[i-1]>='a')
then begin
for j:=1 to length(c) do
c[j]:=chr(ord(c[j])-32);
end;
delete(s,i,1);
if n=3
then begin
for j:=1 to length(c) do
c[j]:='*';
end;
if k=2
then begin
ss:='';
for j:=1 to length(c) do
ss:=ss+copy(c,length(c)-j+1,1);
c:='';
for j:=1 to length(ss) do
c:=c+copy(ss,j,1);
end;
ss:='';
for j:=1 to length(c) do
for o:=1 to m do
ss:=ss+c[j];
insert(ss,s,i);
end;
end;
writeln(s);
end.
