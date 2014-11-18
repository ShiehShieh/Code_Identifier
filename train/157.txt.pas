var i,n,k,x,y,z:longint;
    a:array[1..10000] of longint;
procedure sort(l,r: longint);
var i,j,x,y: longint;
begin
  i:=l;
  j:=r;
  x:=a[(l+r) div 2];
  repeat
    while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
begin
  readln(n);
  readln(k);
  for i:=1 to n do
    read(a[i]);
  repeat
    dec(k);
    for i:=n-1 downto 1 do
      if a[i]<a[i+1] then break;
    x:=i;
    y:=maxlongint;
    for i:=n downto x+1 do
      if (a[i]>a[x]) and (a[i]<y) then
      begin
        y:=a[i];
        z:=i;
      end;
    y:=a[x];
    a[x]:=a[z];
    a[z]:=y;
    sort(x+1,n);
  until k=0;
  for i:=1 to n do
  begin
    write(a[i]);
    if i<>n then write(' ');
  end;
end.

