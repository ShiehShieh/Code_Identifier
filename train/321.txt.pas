program P_1;
var
  ch:char;
  r:array[1..1000,0..1000]of longint;
  data:array[1..1000]of longint;
  a:array[1..1000,0..50]of longint;
  i,j,p,n,m,q:longint;
procedure work(p,q:longint);
var i:longint;
begin
    r[p,q]:=(r[p,q-1]*10+data[q]) mod m;
end;
begin
    while not eoln do
      begin
       inc(n);
       read(ch);
       data[n]:=ord(ch)-ord('0');
      end;
    readln;
    readln(m);
    for j:=1 to n do work(1,j);
    for i:=1 to n do for j:=0 to m do a[i,j]:=maxlongint;
    for i:=1 to n do a[i,r[1,i]mod m]:=0;
    for i:=1 to n do
      for j:=0 to m-1 do
       for p:=i+1 to n do if a[i,j]<>maxlongint then
        begin
         if r[i+1,p]=0 then work(i+1,p);
         q:=j*r[i+1,p]mod m;
         if a[p,q]>a[i,j]+1 then a[p,q]:=a[i,j]+1;
        end;
    for i:=0 to m-1 do if a[n,i]<>maxlongint then break;
    write(i,' ',a[n,i],' ');
    for i:=m-1 downto 1 do if a[n,i]<>maxlongint then break;
    writeln(i,' ',a[n,i]);
end.

