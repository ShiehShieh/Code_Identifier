//vij1006
const
  maxn=1000;
  oo=100000000;
  dir:array[1..4,1..2] of integer= ( (-1,-1),(-1,0),(0,1),(0,-1) );
var
  a:array[1..maxn,1..maxn] of longint;
  f:array[1..maxn,1..maxn] of longint;
  n:integer;
procedure init;
var
 i,j:integer;
begin
  readln(n);
  for i:=1 to n do
  begin
    for j:=1 to i do
    begin
      read(a[i,j]);
    end;
  end;

  for i:=1 to n do
    for j:=1 to i do
    begin
      f[i,j]:=oo;
    end;

end;



procedure solve;
var
  x,y,xn,yn,d,y1:integer;
  min:longint;
  mi:integer;
begin

  f[n,1]:=a[n,1];
  for x:=n downto 1 do
  begin
    min:=oo;
    for y:=1 to x do
    begin
      for d:=1 to 2 do
      begin
        xn:=x-dir[d,1]; yn:=y-dir[d,2];
        if (xn<1) or (xn>n) then
         continue;
        if yn=0 then  yn:=xn;
        if yn=xn+1 then yn:=1;
        if f[xn,yn]+a[x,y]<f[x,y] then
          f[x,y]:=f[xn,yn]+a[x,y];
      end;

      if y=1 then
      begin
        xn:=x+1; yn:=xn;
        if (xn<=n) then
         if f[xn,yn]+a[x,y]<f[x,y] then
          f[x,y]:=f[xn,yn]+a[x,y];
      end
      else if y=x then
      begin
        xn:=x+1; yn:=1;
        if (xn<=n) then
         if f[xn,yn]+a[x,y]<f[x,y] then
          f[x,y]:=f[xn,yn]+a[x,y];
      end;

      if f[x,y]<min then
        begin
          min:=f[x,y];
          mi:=y;
        end;
    end;

    for y1:=1 to x do
    begin
        y:= (y1+mi-1) mod x +1;
        d:=3;

        xn:=x-dir[d,1]; yn:=y-dir[d,2];
        if (xn<1) or (xn>n) then
         continue;
        if yn=0 then  yn:=xn;
        if yn=xn+1 then yn:=1;
        if f[xn,yn]+a[x,y]<f[x,y] then
          f[x,y]:=f[xn,yn]+a[x,y];

    end;

    for y1:=x downto 1 do
    begin
        y:= (y1+mi-1) mod x +1;
        d:=4;

        xn:=x-dir[d,1]; yn:=y-dir[d,2];
        if (xn<1) or (xn>n) then
         continue;
        if yn=0 then  yn:=xn;
        if yn=xn+1 then yn:=1;
        if f[xn,yn]+a[x,y]<f[x,y] then
          f[x,y]:=f[xn,yn]+a[x,y];

    end;

  end;

  writeln(f[1,1]);
end;

begin
  
  init;
  solve;
end.


