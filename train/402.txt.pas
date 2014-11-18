program apple;
var a,b,c,f:array[1..500000]of longint;
    i,j,n,m:longint;
procedure qsort(l,r: longint);
var i,j,x,y: longint;
begin
  i:=l;
  j:=r;
  x:=a[(l+r) div 2];
  repeat
    while a[i]>x do
      inc(i);
    while x>a[j] do
      dec(j);
    if i<=j then begin
                   y:=a[i];
                   a[i]:=a[j];
                   a[j]:=y;
                   inc(i);
                   dec(j);
                 end;
  until i>j;
  if l<j then qsort(l,j);
  if i<r then qsort(i,r);
end;

procedure qsortl(l,r: longint);
var i,j,x,y: longint;
begin
  i:=l;
  j:=r;
  x:=b[(l+r) div 2];
  repeat
    while b[i]>x do
      inc(i);
    while x>b[j] do
      dec(j);
    if (i<=j) then begin
                     y:=b[i];
                     b[i]:=b[j];
                     b[j]:=y;
                     y:=c[i];
                     c[i]:=c[j];
                     c[j]:=y;
                     inc(i);
                     dec(j);
                   end;
  until i>j;
  if l<j then qsortl(l,j);
  if i<r then qsortl(i,r);
end;

begin
  readln(n,m);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to m do
  begin
    read(b[i]);
    c[i]:=i;
  end;
  qsort(1,n);
  qsortl(1,m);
  for i:=1 to m do
    for j:=0 to (n div m) do
      inc(f[c[i]],a[j*m+i]);
  for i:=1 to m do
    write(f[i],' ');
  readln;
  readln;
end.   
