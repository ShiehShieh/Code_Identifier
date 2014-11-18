var
  a:array[1..1000] of integer;
  i,n,len:integer;
procedure high;
var
  i:integer;
begin
    for i:=1 to len do
      a[i]:=a[i]*2;
    for i:=1 to len+1 do
    if a[i]>=10 then
      begin
        inc(a[i+1]);
        dec(a[i],10);
      end;
    if a[len+1]>0 then inc(len);
  end;
begin

  readln(n);
  fillchar(a,sizeof(a),0);
  a[1]:=1;
  len:=1;
  for i:=1 to n+1 do
    high;
  dec(a[1],2);
  for i:=len downto 1 do
    write(a[i])



end.


