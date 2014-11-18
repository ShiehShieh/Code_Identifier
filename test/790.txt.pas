program ksdad;
var
b:array[0..501,0..501]of boolean;
c:array[0..501,0..501]of char;
m,n,o,p,q:longint;

procedure sou(i,j:longint);
begin
b[i,j]:=false;
dec(q);
if(b[i+1,j])and(c[i+1,j]='0')
then sou(i+1,j);
if(b[i-1,j])and(c[i-1,j]='0')
then sou(i-1,j);
if(b[i,j-1])and(c[i,j-1]='0')
then sou(i,j-1);
if(b[i,j+1])and(c[i,j+1]='0')
then sou(i,j+1);
end;

begin
readln(m,n);
q:=m*n;
for o:=1to m do
begin
for p:=1to n do
begin
read(c[o,p]);
b[o,p]:=true;
if c[o,p]='*'
then dec(q);
end;
readln;
end;
for o:=1to n do
if(b[1,o])and(c[1,o]='0')
then sou(1,o);
for o:=1to n do
if(b[m,o])and(c[m,o]='0')
then sou(m,o);
for o:=1to m do
if(b[o,1])and(c[o,1]='0')
then sou(o,1);
for o:=1to m do
if(b[o,n])and(c[o,n]='0')
then sou(o,n);
writeln(q);
end.
