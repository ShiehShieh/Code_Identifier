var
 a,b,c:longint;
 f:array[1..20,1..20,1..20] of longint;
procedure mf;
 var
i,j,k:integer;
 function m(i,j,k:integer):longint;
begin
  if (i<=0) or (j<=0) or (k<=0)
then exit(1)
else exit(f[i,j,k]);
end;

 begin
  for i:=1 to 20 do
   for j:=1 to 20 do
    for k:=1 to 20 do
  begin
  if (i<j) and (j<k)
  then f[i,j,k]:=m(i,j,k-1)+m(i,j-1,k-1)-m(i,j-1,k)
  else f[i,j,k]:=m(i-1,j,k)+m(i-1,j-1,k)+m(i-1,j,k-1)-m(i-1,j-1,k-1);
  end;
 end;

begin
 mf;
 readln(a,b,c);
 while not((a=-1) and (b=-1) and (c=-1)) do
begin
  write('w(',a,',',b,',',c,')=');
  if (a<=0) or (b<=0) or (c<=0)
  then writeln(1)
  else
   if (a>20) or (b>20) or (c>20)
   then writeln(f[20,20,20])
   else writeln(f[a,b,c]);
  readln(a,b,c);
 end;
end.

