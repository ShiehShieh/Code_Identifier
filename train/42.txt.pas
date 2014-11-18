type
 arr=array[0..10,0..10]of int64;
var
  m,n,i,j:longint;
  x:array[0..10] of int64;
  a,b:array[0..10,0..10]of int64;
procedure cheng(var a,b:arr);
var i,j,k:longint; c:arr;
begin
 fillchar(c,sizeof(c),0);
  for i:=1 to m do
   for j:=1 to m do
    for k:=1 to m do
      c[i,j]:=(c[i,j]+(a[i,k]mod 7777777)*(b[k,j]mod 7777777))mod 7777777;
   a:=c;
end;
begin
  readln(m);readln(n);
  for i:=1 to m-1 do a[i,i+1]:=1;
  for i:=1 to m do a[m,i]:=1;
  b:=a; n:=n-1;
//  n:=n shr 1;
  while n<>0 do
   begin
     if n and 1=1 then cheng(b,a);
     if n<>0 then cheng(a,a);
     n:=n div 2;
   end;

// for i:=1 to m do   begin
//  for j:=1 to m do
    write(b[m,m]); //  writeln;end;




end.


