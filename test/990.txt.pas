var
  s1,s2:ansistring;
  i,j,n:longint;
  f:array[0..5000,0..5000]of integer;

function max(a,b:longint):longint;
begin
  if a>b then exit(a)
  else exit(b);
end;

procedure main;
begin
  readln(n);
  readln(s1);
  for i:=n downto 1 do
    s2:=s2+s1[i];
  for i:=1 to n do
    for j:=1 to n do begin
      if s1[i]=s2[j] then
        f[i,j]:=f[i-1,j-1]+1
      else f[i,j]:=max(f[i-1,j],f[i,j-1]);
    end;
  writeln(n-f[n,n]);
end;

begin
  main;
end.

