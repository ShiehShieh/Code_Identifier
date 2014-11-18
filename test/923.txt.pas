var a:array[1..26] of longint;
    i,j,k,s,t,w:longint;
    c:char;
procedure jian(s:longint);
var i,j,k:longint;
begin
  inc(a[s]);
  if a[s]>t+s-w then
    if s=1 then halt
      else jian(s-1)
        else
          begin
            for i:=s+1 to w do a[i]:=a[i-1]+1;
            for i:=1 to w do write(chr(a[i]));
          end;
end;
begin
  readln(s,t,w);
  for i:=1 to w do
    begin read(c);a[i]:=ord(c); end;
  t:=ord('a')+t-1;
  for i:=1 to 4 do
    begin jian(w);writeln; end;
  jian(w);
end.





