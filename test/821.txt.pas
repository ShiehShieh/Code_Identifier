program Random;

var
  a, b: array[0..100] of Longint;
  n, i, j, t: Longint;
begin
  Readln(n);
  for i := 1 to n do
    Read(a[i]);
  for i := 1 to n - 1 do
    for j := n downto i + 1 do
      if a[j - 1] > a[j] then
      begin
        t := a[j];
        a[j] := a[j - 1];
        a[j - 1] := t;
      end;
  i := 1;
  j := 0;
  repeat
    if a[i - 1] <> a[i] then
    begin
      Inc(j);
      b[j] := a[i];
    end;
    i := i + 1;
  until i = n + 1;
  Writeln(j);
  for i := 1 to j - 1 do
    Write(b[i], ' ');
  Writeln(b[j]);
end.
