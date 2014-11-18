program P1347(input,output);
var
  f:array[0..6,1..40] of longint;
  g:array[1..40,1..40] of longint;
  ch:char;
  n,k,i,j,l:integer;
begin
  readln(n,k);
  for i:=1 to n do
    begin
      read(ch);
      g[i,i]:=ord(ch)-48;
    end;
  for i:=1 to n do
    for j:=i+1 to n do
      g[i,j]:=g[i,j-1]*10+g[j,j];

  for i:=1 to n do f[0,i]:=g[1,i];
  for i:=1 to k do
    for j:=1 to n do
      for l:=i to j-1 do
        if f[i-1,l]*g[l+1,j]>f[i,j] then
          f[i,j]:=f[i-1,l]*g[l+1,j];
  writeln(f[k,n]);
end.


