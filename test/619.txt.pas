//vij1057
const
  maxn=1000;
var
  f:array[1..maxn,1..maxn] of integer;
  a:array[1..maxn,1..maxn] of boolean;
  n,m:integer;
procedure init;
var
  i,j,c:integer;
begin
  readln(n,m);
  for i:=1 to n do
    for j:=1 to m do
    begin
      read(c);
      case c of
      0: a[i,j]:=false;
      1: a[i,j]:=true;
      end;
    end;
end;

procedure solve;
var
  i,j,k,max,max1,totMax:integer;
begin
  totMax:=0;

  for i:=1 to n do
    for j:=1 to m do
  begin
    if a[i,j] then max:=1
      else max:=0;
    if (i>1) and (j>1) then
    begin

      max1:=f[i-1,j-1];
      k:=0;
      while k<=max1 do
      begin
        if a[i-k,j] and a[i,j-k] then
          inc(k)
        else break;
      end;

      if k=max1+1 then
        max:=k;

    end;

    if max>totMax then
      totMax:=max;

    f[i,j]:=max;
  end;

  writeln(totMax);
end;

begin
  
  init;
  solve;
end.
