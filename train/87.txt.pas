type arr=array[0..510]of longint;
var ss,x,q,i,j:longint;
    a,m:arr;
    p:array[0..25]of arr;
procedure cheng(a,b:arr;var c:arr);
var i,j:longint;
begin
fillchar(c,sizeof(c),0);
  for i:=1 to a[0] do
    for j:=1 to b[0] do
      if i+j<510 then
        begin
          inc(c[i+j-1],a[i]*b[j]);
          inc(c[i+j],c[i+j-1]div 10);
          c[i+j-1]:=c[i+j-1]mod 10;
        end;
  c[0]:=a[0]+b[0];
  if c[0]>500 then c[0]:=500;
  while (c[0]>1)and(c[c[0]]=0) do dec(c[0]);
end;
begin

  readln(q);
  x:=trunc(q*ln(2)/ln(10))+1;
  writeln(x);
  a[0]:=0;
  while q div 2<>0 do
    begin
      inc(a[0]);
      a[a[0]]:=q mod 2;
      q:=q div 2;
    end;
    inc(a[0]);
    a[a[0]]:=1;
  fillchar(p,sizeof(p),0);
  p[0][1]:=2;
  p[0][0]:=1;
  for i:=0 to 24 do
    cheng(p[i],p[i],p[i+1]);
    m[1]:=1;
    m[0]:=1;
  for i:=1to a[0] do
    begin
      if a[i]=1 then cheng(p[i-1],m,m);
    end;
  if m[1]>0 then dec(m[1]);
  write(m[500]);
  for i:=499 downto 1 do
    begin
    if i mod 50=0 then writeln;
      write(m[i]);
    end;
end.


