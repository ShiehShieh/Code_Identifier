var
 n,m,i,j,k,sum,l:longint;
 a,b:array[1..2000] of longint;
 f:array[1..2000] of boolean;
begin
 read(n,m);
 for i:=1 to n do
  read(a[i]);
 for i:=1 to m do
  read(b[i]);
 fillchar(f,sizeof(f),true);
 sum:=m;
 for i:=1 to n do
  begin
  k:=-1;
  for j:=1 to m do
   if (b[j]>0)and(f[j])and(a[i]>b[j])and(b[j]>k) then
    begin
     k:=b[j];
     l:=j;
    end;
  if k<>-1 then
   begin
    f[l]:=false;
    dec(sum);
   end;
  end;
 writeln(sum);
end.
