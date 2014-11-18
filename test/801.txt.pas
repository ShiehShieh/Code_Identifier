program p1128;
var a:array[0..10000] of longint;b:array[0..10000] of boolean;
i,k,s,n:longint;xx:boolean;
procedure check(sum:longint);
var j:longint;
begin
xx:=true;
if sum<2 then xx:=false;
if sum<>2 then begin
for j:=2 to trunc(sqrt(sum)) do
if sum mod j=0 then begin xx:=false;break;end;
end;
end;
procedure try(sum,x,y:longint);
var i:longint;
begin
for i:=1 to n do begin
if (y<i) and b[i] then begin
sum:=sum+a[i];
b[i]:=false;
if x<k then try(sum,x+1,i) else begin check(sum);if xx then inc(s);end;
b[i]:=true;
sum:=sum-a[i];
end;
end;
end;
begin
readln(n,k);
for i:=1 to n do
read(a[i]);
fillchar(b,sizeof(b),#1);
try(0,1,0);
writeln(s);
end.

