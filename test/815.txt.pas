var
 i,j,k,n,m:longint;
 a:array[-1..102,-1..102]of char;
 b:array[-1..102,-1..102]of boolean;

procedure li(x,y:longint);
var
 i,j:longint;
begin
for i:=1 to 2 do
 if (a[x+i,y]='#')and(not b[x+i,y])
 then begin
   b[x+i,y]:=true;
   li(x+i,y);
   end;

for i:=1 to 2 do
 if (a[x,y+i]='#')and(not b[x,y+i])
 then begin
   b[x,y+i]:=true;
   li(x,y+i);
   end;

if (a[x+1,y+1]='#')and(not b[x+1,y+1])
then begin
 b[x+1,y+1]:=true;
 li(x+1,y+1);
 end;

for i:=1 to 2 do
 if (a[x-i,y]='#')and(not b[x-i,y])
 then begin
   b[x-i,y]:=true;
   li(x-i,y);
   end;

for i:=1 to 2 do
 if (a[x,y-i]='#')and(not b[x,y-i])
 then begin
   b[x,y-i]:=true;
   li(x,y-i);
   end;

if (a[x+1,y-1]='#')and(not b[x+1,y-1])
then begin
 b[x+1,y-1]:=true;
 li(x+1,y-1);
 end;

if (a[x-1,y+1]='#')and(not b[x-1,y+1])
then begin
 b[x-1,y+1]:=true;
 li(x-1,y+1);
 end;

if (a[x-1,y-1]='#')and(not b[x-1,y-1])
then begin
 b[x-1,y-1]:=true;
 li(x-1,y-1);
 end;
end;





begin
fillchar(b,sizeof(b),false);
 readln(N,m);
for i:=1 to n do
begin
 for j:=1 to m do
  read(a[i,j]);
  readln;
end;
k:=0;
for i:=1 to n do
for j:=1 to m do
 if (a[i,j]='#')and(not b[i,j]) then
   begin
     inc(k);
     li(i,j);
   end;
write(k);
end.
