//vij1037
const
  maxn=100;
  maxh=5000;
var
  f1,f2:array[0..maxn,0..maxh] of integer;
  h:array[1..maxn] of integer;
  n,th:integer;
procedure init;
var
  i:integer;
begin
  readln(n);
  th:=0;
  for i:=1 to n do
  begin
    read(h[i]);
    th:=th+h[i];
  end;

end;

procedure solve;
var
  i,j:integer;
  max:integer;
  temp:integer;
  hi:integer;
begin

  for i:=1 to n do
   for j:=0 to th do
    f2[i,j]:=-10000;
  f2[1,h[1]]:=h[1];
  f2[1,0]:=0;
  for i:=2 to n do
  begin
    hi:=h[i];
    for j:=0 to th do
    begin
      temp:=f2[i-1,j];

      if f2[i-1,j+hi] > temp then
        temp:=f2[i-1,j+hi];

      if(j>=hi )and(f2[i-1,j-hi]+hi>temp) then
        temp:=f2[i-1,j-hi] + hi;

      if ( j<hi ) and (f2[i-1,hi-j]+j>temp) then
        temp:= f2[i-1,hi-j]+j;

      f2[i,j]:=temp;
    end;

  end;

  max:=f2[n,0];
  if max<=0 then
    writeln('Impossible')
  else
    writeln(max);
end;

begin
  
  init;
  solve;
end.


