type
  hp=array[1..1000000]of longint;
var
  a:hp;
  n,b,s:longint;

procedure swap(var a,b:longint);
var
  t:longint;
begin
  t:=a;
  a:=b;
  b:=t;
end;

procedure tj(b:longint);
var
  i,t:longint;
begin
  t:=1;
  i:=n;
  while i>t do
  begin
    If a[i]+a[t]<=b then
    begin
      inc(s);
      inc(t);
      dec(i);
    end
    else
    begin
      inc(s);
      dec(i);
    end;
  end;
  If i=t then inc(s);
end;
function qsort(l,r:longint):longint;
var
  i,j,m:longint;
begin
  If l>=r then exit;
  m:=a[(l+r)div 2];
  i:=l;
  j:=r;
  repeat
    while a[i]<m do inc(i);
    while a[j]>m do dec(j);
    If i<=j then
    begin
      swap(a[i],a[j]);
      inc(i);
      dec(j);
    end;
  until i>j;
  qsort(l,j);
  qsort(i,r);
end;

procedure readdata;
var
  i:longint;
begin
  readln(b);
  readln(n);
  for i:=1 to n do readln(a[i]);
end;

procedure print;
begin
  writeln(s);
end;

begin
  readdata;
  qsort(1,n);
  s:=0;
  tj(b);
  print;
end.
