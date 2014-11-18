var
  a:array[1..30000] of longint;
  n,s,w:longint;
  boo:array[1..30000] of boolean;
procedure readdata;
var i:longint;
begin
  fillchar(boo,sizeof(boo),true);
  readln(w);
  readln(n);
  for i:=1 to n do
  readln(a[i]);
  s:=n;
end;
procedure swap(var a,b:longint);
var t:longint;
begin
  t:=a;
  a:=b;
  b:=t;
end;
procedure qsort(l,r:longint);
var i,j,m:longint;
begin
  if l>r then exit;
  m:=a[(l+r) div 2];
  i:=l;
  j:=r;
  repeat
    while m>a[i] do inc(i);
    while m<a[j] do dec(j);
    if i<=j then begin
    swap(a[i],a[j]);
    inc(i);
    dec(j);
    end;
  until i>j;
  qsort(i,r);
  qsort(l,j);
end;
procedure cr;
var i,j,t:longint;
begin
  t:=1;
  for i:=n downto 2 do
  if (a[t]+a[i]<=w)and(t<i)and(boo[t])and(boo[i]) then begin s:=s-1; t:=t+1; boo[t-1]:=false; end;
end;
begin
  readdata;
  qsort(1,n);
  cr;
  writeln(s);
end.

