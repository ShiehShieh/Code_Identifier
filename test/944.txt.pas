program p1071(input,output);
var i,j,n,m,t:longint;
    a,s:array[1..100]of longint;
    f,g,h:array[0..100000]of longint;
begin
  readln(t);
  readln(n);
  for i:=1 to n do
  begin
    readln(a[i]);
    inc(m,a[i]);
  end;
  m:=m-t;
  if m<0 then
  begin
    writeln('0');
    halt;
  end;
  f[0]:=1;
  for i:=1 to n do
    for j:=m-a[i] downto 0 do
      if f[j]<>0 then
      begin
        if f[j+a[i]]=0 then
        begin
          g[j+a[i]]:=j;
          h[j+a[i]]:=i;
        end;
        inc(f[j+a[i]],f[j]);
      end;
  i:=m;
  j:=0;
  while g[i]<>0 do
  begin
    inc(j);
    s[j]:=h[i];
    i:=g[i];
  end;
  inc(j);
  s[j]:=h[i];
  if f[m]=0 then writeln('0');
  if f[m]>1 then writeln('-1');
  if f[m]=1 then
    for i:=j downto 1 do
      write(s[i],' ');
end.
