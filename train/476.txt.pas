type
 ayy=array[1..250] of integer;
var
 n,i,j,k:longint;
 f:array[0..800] of ayy;
 l:array[0..800] of integer;
procedure ys(i,j:integer);
 var
  x:longint;
 begin
  for x:=1 to l[j] do
   f[i][x]:=f[i][x]+f[j][x]*2;
  if l[j]>l[i] then
   l[i]:=l[j];
  f[i][1]:=f[i][1]+1;
  for x:=1 to l[i]+1 do
   begin
    f[i][x+1]:=f[i][x+1]+f[i][x] div 10;
    f[i][x]:=f[i][x] mod 10;
   end;
  l[i]:=l[i]+2;
  while f[i][l[i]]=0 do
   dec(l[i]);
 end;
begin
 readln(n);
 f[0][1]:=0;
 l[0]:=1;
 f[1][1]:=1;
 l[1]:=1;
 f[2][1]:=2;
 l[2]:=1;
 for i:=3 to n do
  begin
   for j:=i-2 downto 1 do
    ys(i,j);
   f[i][1]:=f[i][1]+2;
   for k:=1 to l[i] do
    begin
     f[i][k+1]:=f[i][k+1]+f[i][k] div 10;
     f[i][k]:=f[i][k] mod 10;
    end;
   if f[i][l[i]+1]<>0 then
    inc(l[i]);
  end;
 for i:=l[n] downto 1 do
  write(f[n][i]);
 writeln;
end.

