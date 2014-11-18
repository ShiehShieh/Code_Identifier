program ex1;
var a:array[1..1000] of longint;
    n,k,i,sum,m:longint;
function sushu(s:longint):boolean;
var i:longint;
begin
 if s=1 then exit(false);
 if s=2 then exit(true);
 if s mod 2=0 then exit(false);
 for i:=3 to trunc(sqrt(s)) do
  if s mod i=0 then exit(false);
 exit(true);
end;
procedure search(l,p:longint);
var i:integer;
begin
 if l>k then
 begin
  if sushu(m) then
    inc(sum);
  exit;
end;
 for i:=p+1 to n do
  begin
   m:=m+a[i];
   search(l+1,i);
   m:=m-a[i];
  end;
end;
begin
 readln(n,k);
 for i:=1 to n do
  read(a[i]);
 sum:=0;
 search(1,0);
 writeln(sum);
end.

