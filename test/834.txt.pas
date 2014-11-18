var
n:integer;
function p(k:longint):boolean;
var
i:longint;
Begin
if k=1 then exit(false);
for i:=2 to trunc(sqrt(k))do
if (k mod i=0) then exit(false);
exit(true);
end;
procedure doit(a:longint;s:string);
var
s1,s2:string;
k,i,code:longint;
begin
if a=n+1 then begin writeln(s);exit; end;
if a=1 then
for i:=1 to 9 do
begin
str(i,s1);
s2:=s+s1;
val(s2,k,code);
if p(k) then doit(a+1,s2);
end
else
for i:=0 to 9 do
begin
str(i,s1);
s2:=s+s1;
val(s2,k,code);
if p(k) then doit(a+1,s2);
end;
end;
begin
readln(n);
doit(1,'');
end.
