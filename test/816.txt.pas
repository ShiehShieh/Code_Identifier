var
 k,i,j:longint;
 a:array[0..1000] of integer;
begin
 readln(k);
 a[1]:=2;
 a[0]:=1;
for i:=2 to k do
 begin
  for j:=1 to a[0] do
   a[j]:=a[j]*2;
  a[1]:=a[1]+2;
  for j:=1 to a[0] do
    begin
     a[j+1]:=a[j+1]+a[j] div 10;
     a[j]:=a[j] mod 10;
    end;
  while a[a[0]+1]<>0 do
   inc(a[0]);
  end;
 for i:=a[0] downto 1 do
  write(a[i]);
end.
