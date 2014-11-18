program two_tower;
  var
    a:array[1..100]of integer;
    f:array[0..100,0..2000]of integer;
    n,i,j,k,m:integer;
function max(x,y,z:integer):integer;
  begin
    if(x>y)and(x>z)then exit(x);
    if y>z then exit(y);
    exit(z);
  end;
  begin
    readln(n);
    for i:=1 to n do
      begin
        read(a[i]);
        inc(m,a[i]);
      end;
    m:=m div 2;
    for i:=0 to n do
      for j:=0 to m do
        f[i,j]:=-2000;
    f[0,0]:=0;
    for i:=1 to n do
      begin
        for j:=0 to a[i] do
          f[i,j]:=max(f[i-1,j],f[i-1,j+a[i]],f[i-1,a[i]-j]+j);
        for j:=a[i]+1 to m do
          f[i,j]:=max(f[i-1,j],f[i-1,j+a[i]],f[i-1,j-a[i]]+a[i]);
      end;
    if f[n,0]<=0 then
      writeln('Impossible')
    else
      writeln(f[n,0]);
  end.
