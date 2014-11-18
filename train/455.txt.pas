program paper;
var a:array[1..50,1..50] of integer;
    f:array[0..50,0..50,1..100] of integer;
    n,i,j,k,l,m,x1,x2,y1,y2,sol:longint;
function max(t1,t2,t3,t4:integer):integer;
var ans:integer;
begin
  ans:=t1;
  if ans<t2 then ans:=t2;
  if ans<t3 then ans:=t3;
  if ans<t4 then ans:=t4;
  max:=ans;
end;
begin
  readln(m,n);
  for i:=1 to m do
  begin
    for j:=1 to n do
      read(a[j,i]);
    readln;
  end;

  for k:=2 to m+n do
  for x1:=1 to n do
  for x2:=1 to n do
  if (k-x1>0)and(k-x2>0)and(x1<>x2) then
  begin
    y1:=k-x1;
    y2:=k-x2;
    f[x1,x2,k]:=max(f[x1-1,x2-1,k-1],f[x1-1,x2,k-1],f[x1,x2-1,k-1],f[x1,x2,k-1])+a[x1,y1]+a[x2,y2];
  end;
  sol:=f[n-1,n,k-1]+a[n,m];
  writeln(sol);
end.
