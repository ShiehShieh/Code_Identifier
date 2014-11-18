program dd;
  var
    n,y,shu:longint;
    a:array[0..101] of longint;
  procedure Sort(l, r: Integer);
  var
    i,j,x,y:integer;
  begin
    i:=l; j:=r; x:=a[(l+r) div 2];
    repeat
      while a[i]<x do i:=i+1;
      while x<a[j] do j:=j-1;
      if i<=j then
      begin
        y:=a[i]; a[i]:=a[j]; a[j]:=y;
        i:=i+1; j:=j-1;
      end;
    until i>j;
    if l<j then Sort(l,j);
    if i<r then Sort(i,r);
  end;

begin
  read(n);
  for y:=1 to n do
    read(a[y]);
  sort(1,n);

  shu:=n;
  for y:=2 to n do
    if a[y]=a[y-1] then dec(shu);
  writeln(shu);
  write(a[1]);
  for y:=2 to n do
    if a[y]<>a[y-1] then write(' ',a[y]);
end.
