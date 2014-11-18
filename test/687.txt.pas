var n,k,ans,i:longint;
    a:array[1..20] of longint;
    f:boolean;
procedure search(c,x,s:longint);
var i:longint;
begin
  if c>k then
  begin
    if s=1 then exit;
    f:=true;
    for i:=2 to trunc(sqrt(s)) do
      if s mod i=0 then begin
                          f:=false;
                          break;
                        end;
    if f then inc(ans);
    exit;
  end;
  for i:=x to n-k+c do
    search(c+1,i+1,s+a[i]);
end;
begin
  ans:=0;
  readln(n,k);
  for i:=1 to n do
    read(a[i]);
  search(1,1,0);
  writeln(ans);
end.

