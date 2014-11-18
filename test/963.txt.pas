program lx111;
var a:array[1..200,1..200]of longint;n,i,m,s:longint;
    f:array[1..200]of boolean;
procedure try(x:longint);
var i:longint;
begin
  f[x]:=false;
  for i:=1 to n do
    if (a[x,i]=1)and f[i] then begin a[x,i]:=0;try(i);end;
end;
begin
  readln(n);
  for i:=1 to n do
    begin
      read(m);
      while m<>0 do
        begin
          a[i,m]:=1;
          read(m);
        end;
      readln;
    end;
  for i:=1 to n do
    f[i]:=true;
  for i:=1 to n do
    if f[i] then
      begin
        s:=s+1;
        try(i);
      end;
  writeln(s);
end.
