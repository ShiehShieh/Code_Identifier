program p1054;
const filename='p1054';
var
  f:array[0..5000000]of boolean;
  k,x,i,j,n,m,y:longint;
  a:array[1..3000]of boolean;
  b:array[1..3000]of longint;
procedure print(x:longint);
begin
  write(x);
  halt
end;
function gcd(x,y:longint):longint;
begin
  if y=0 then exit(x)
  else gcd:=gcd(y,x mod y);
end;
begin
  readln(n,m);
  for i:=1 to n do
  begin
    readln(k);
    for j:=k downto k-m do
     if j<=0 then break
     else a[j]:=true;
  end;
  k:=0;
  y:=1; while not a[y] do inc(y);
  if y=1 then  print(-1);
  for i:=1 to 3000 do
    if a[i] then
    begin inc(k); b[k]:=i; end;
  x:=gcd(b[1],b[2]);
  for i:=3 to k do x:=gcd(x,b[i]);
  if x<>1 then print(-1);
  x:=0; f[0]:=true;
  for i:=1 to maxlongint do
  begin
    for j:=1 to k do
      if i<b[j] then break
      else
       if f[i-b[j]] then
       begin f[i]:=true; break; end;
    if f[i] then inc(x)
    else x:=0;
    if x=y then  print(i-y);
  end;
end. 
