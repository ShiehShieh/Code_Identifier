const
  nn=100;mm=10;
type
  int=longint;
  arr=array[1..nn] of int;
var
  a,b:arr; u:arr;
  c:array[1..mm] of arr;
  n,m,k,i:int;
operator *(a,b:arr) c:arr;
var i:int;
begin
  for i:=1 to n do
    c[i]:=a[b[i]];
end;
function pow(a:arr; b:int):arr;
begin
  pow:=u;
  while b<>0 do
  begin
    if b and 1 = 1 then pow:=pow*a;
    b:=b shr 1; a:=a*a;
  end;
end;
procedure print(a:arr);
var i:Int;
begin
  for i:=1 to n do
    write(a[i],' ');
  writeln;
end;

procedure init;
var  i,j:int;
begin
  readln(n,m,k);
  for i:=1 to n do
    u[i]:=i;
  a:=u; b:=u;
  
  for i:=1 to m do
  begin
    for j:=1 to n do
      read(c[i,j]);
    b:=b*c[i];
  //print(b);
  end;
end;

begin
  init;
  a:=pow(b,k div m);
  for i:=1 to k mod m do
    a:=a*c[i];
  print(a);
  //readln(n);
end.
          
