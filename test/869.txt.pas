type inf=record
 x,y:array[0..1000]of longint;
 top:longint;
 end;
var n:longint;way:inf;
bin:array[0..1000]of longint;
procedure init;
 var i,z,k:longint;
 begin
readln(n);
z:=0;
for i:=1 to n do
  begin
read(k);
while k<>0 do
  begin
inc(z);
way.x[z]:=i;
way.y[z]:=k;
read(k);
  end;
bin[i]:=i;
  end;
way.top:=z;
  end;
function getit(n:longint):longint;
 begin
if n=bin[n] then getit:=n
else
  begin
bin[n]:=getit(bin[n]);
getit:=bin[n];
  end;
 end;
procedure run;
 var i,x1,x2:longint;
 begin
for i:=1 to way.top do
  begin
x1:=getit(way.x[i]);
x2:=getit(way.y[i]);
if x1<>x2 then
  begin
bin[x1]:=bin[x2];
  end;
  end;
for i:=1 to n do
  begin
bin[i]:=getit(bin[i]);
  end;
 end;
procedure outit;
 var b:array[0..1000]of boolean;k,i:longint;
 begin
fillchar(b,sizeof(b),0);
k:=0;
for i:=1 to n do if not(b[bin[i]]) then begin inc(k);b[bin[i]]:=true;end;
writeln(k);
  end;
begin
 init;
 run;
 outit;
end.

