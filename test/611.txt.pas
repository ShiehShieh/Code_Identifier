var
  d:array[1..100000]of longint;
  n,k:longint;
  s:integer;

procedure init;
var
  i:longint;
begin
  readln(k);
  readln(n);
  begin
    for i:=1 to n do read(d[i]);
    readln;
  end;
end;

procedure swap(var a,b:longint);
var
  t:longint;
begin
  t:=a;
  a:=b;
  b:=t;
end;

procedure qsort(left,right:longint);
var
  i,j,m:longint;
begin
  if left>=right then exit;
  i:=left;
  j:=right;
  m:=d[(left+right) div 2];
  repeat
    while d[i]<m do inc(i);
    while d[j]>m do dec(j);
    if i<=j then
    begin
      swap(d[i],d[j]);
      inc(i);
      dec(j);
    end;
  until i>j;
  qsort(left,j);
  qsort(i,right);
end;

procedure aa(var s:integer);
var
  i,j:integer;
begin
  i:=1;
  j:=n;
  while i<=j do
  begin
    if d[i]+d[j]>k then dec(j)
    else if d[i]+d[j]<=k then begin inc(i); dec(j); end;
    inc(s);
  end;
end;

begin
  init;
  qsort(1,n);
  aa(s);
  writeln(s);
end.

