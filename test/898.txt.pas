program p1153;
type re=array[1..200] of longint;
var i, j, k: longint;
    n, m: longint;
    a: re;
    ans1, ans2: longint;
procedure work(a: re;n: longint);
var i, j, k: longint;
    s: array[1..2] of longint;
begin
  s[1] := 0;
  s[2] := 0;
  while n > 0 do
  begin
    k := random(n);
    inc(s[n mod 2 + 1],a[k+1]);
    a[k+1] := a[n];
    dec(n);
  end;
  if abs(s[1]-s[2])<abs(ans1-ans2) then
  begin
    ans1 := s[1];
    ans2 := s[2];
  end;
end;
begin
  readln(n);
  randomize;
  for i := 1 to n do
    readln(a[i]);
  ans1 := 0;
  ans2 := 10000;
  for i := 1 to 10000 do
    work(a,n);
  if ans1 < ans2 then writeln(ans1,' ',ans2)
                 else writeln(ans2,' ',ans1);
end.
