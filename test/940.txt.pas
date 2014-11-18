program gaosixiaoyuan;
type
  sz=array[1..140] of real;
var
  a:array[1..140] of sz;
  jh,jg:sz;
  n,i,j,k,l:integer;
  x,y:real;
begin

  readln(n);
  for i:=1 to n do
   for j:=1 to n+1 do
    read(a[i,j]);
  for i:=1 to n-1 do
   begin
    l:=i;
    while (a[l,i]=0)and(l<=n) do
     inc(l);
    jh:=a[l];
    a[l]:=a[i];
    a[i]:=jh;
    for j:=i+1 to n do
     begin
     x:=a[i,i];
     y:=a[j,i];
     for k:=1 to n+1 do
      a[j,k]:=a[j,k]-a[i,k]*(y/x);
     end;
   end;
  if a[n,n]=0 then
   begin
    if a[n,n+1]=0 then
     writeln('Ununique so1ution')
    else
     writeln('No so1ution');
   end
  else
  begin
  jg[n]:=a[n,n+1]/a[n,n];
  for i:=n-1 downto 1 do
   begin
    x:=0;
    for j:=i+1 to n do
     x:=x+jg[j]*a[i,j];
    jg[i]:=(a[i,n+1]-x)/a[i,i];
   end;
  for i:=1 to n do
   if abs(jg[i])<=0.0000001 then
    write(0,' ')
   else
    write(jg[i]:0:0,' ');
  end;
end.
