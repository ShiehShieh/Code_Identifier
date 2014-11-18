type
  ba=array[1..1000] of longint;
Var
  a,b,c,d,ds1,ds2:ba;
  k,l,dk,m,n,i,j,x,y,x1,y1,l1,l2:longint;
Procedure sort1(l,r:integer);
var
  i,j,x,t:longint;
Begin
  i:=l;
  j:=r;
  x:=a[(l+r) div 2];
  repeat
    while a[i]>x do
      inc(i);
    while a[j]<x do
      dec(j);
    if i<=j
      then
        begin
          t:=a[i];
          a[i]:=a[j];
          a[j]:=t;
          t:=b[i];
          b[i]:=b[j];
          b[j]:=t;
          inc(i);
          dec(j);
        end
  until i>j;
  if i<r
    then
      sort1(i,r);
  if j>l
    then
      sort1(l,j);
End;
Procedure sort2(l,r:integer);
var
  i,j,x,t:longint;
Begin
  i:=l;
  j:=r;
  x:=c[(l+r) div 2];
  repeat
    while c[i]>x do
      inc(i);
    while c[j]<x do
      dec(j);
    if i<=j
      then
        begin
          t:=c[i];
          c[i]:=c[j];
          c[j]:=t;
          t:=d[i];
          d[i]:=d[j];
          d[j]:=t;
          inc(i);
          dec(j);
        end
  until i>j;
  if i<r
    then
      sort2(i,r);
  if j>l
    then
      sort2(l,j);
End;
Procedure sort3(l,r:integer);
var
  i,j,x,t:longint;
Begin
  i:=l;
  j:=r;
  x:=b[(l+r) div 2];
  repeat
    while b[i]<x do
      inc(i);
    while b[j]>x do
      dec(j);
    if i<=j
      then
        begin
          t:=b[i];
          b[i]:=b[j];
          b[j]:=t;
          inc(i);
          dec(j);
        end
  until i>j;
  if i<r
    then
      sort3(i,r);
  if j>l
    then
      sort3(l,j);
End;
Procedure sort4(l,r:integer);
var
  i,j,x,t:longint;
Begin
  i:=l;
  j:=r;
  x:=d[(l+r) div 2];
  repeat
    while d[i]<x do
      inc(i);
    while d[j]>x do
      dec(j);
    if i<=j
      then
        begin
          t:=d[i];
          d[i]:=d[j];
          d[j]:=t;
          inc(i);
          dec(j);
        end
  until i>j;
  if i<r
    then
      sort4(i,r);
  if j>l
    then
      sort4(l,j);
End;
function min(a,b:longint):longint;
begin
  if a<b
    then
      exit(a)
    else
      exit(b);
end;
Begin
  readln(m,n,k,l,dk);
  for i:=1 to dk do
    begin
      readln(x,y,x1,y1);
      if abs(x-x1)=1
        then
          BEGIN
            inc(a[min(x,x1)]);
            b[min(x,x1)]:=min(x,x1);
          end
        else
          begin
            inc(c[min(y,y1)]);
            d[min(y,y1)]:=min(y,y1);
          end;
    end;
  sort1(1,m);
  sort2(1,n);
  sort3(1,k);
  sort4(1,l);
  for i:=1 to k do
    write(b[i],' ');
  writeln;
  for i:=1 to l do
    write(d[i],' ');
End.


