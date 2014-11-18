program fruit;
var a:array[1..10001] of longint;
    b:array[1..10000] of longint;
    i,j,k,p,q,a0,b0,ans,n:longint;
procedure sort(s,t:integer);
var x,y:longint;
begin
  if s>=t then exit;
  i:=s;j:=t;x:=a[s+random(t-s)];
  repeat
    while a[i]<x do inc(i);
    while a[j]>x do dec(j);
    if i<=j then
      begin
        y:=a[i];a[i]:=a[j];a[j]:=y;
        inc(i);dec(j);
      end;
  until i>j;
  sort(s,j);
  sort(i,t);
end;
procedure getmin(var min:longint);
begin
  if (b0<=k) and (b[b0]<a[a0]) then begin min:=b[b0];inc(b0);end
                               else begin min:=a[a0];inc(a0);end;
end;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  readln;sort(1,n);ans:=0;
  a[n+1]:=maxlongint;
  if n>1 then
    begin
      inc(ans,a[1]+a[2]);
      a0:=3;b0:=1;k:=1;b[1]:=ans;
      while (a0<=n) or (b0<k) do
         begin
           getmin(p);
           getmin(q);
           inc(ans,p+q);
           inc(k);b[k]:=p+q;
         end;
      end;
  writeln(ans);
end.
