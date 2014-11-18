program p1001;
var i,i1,i2,j,m,n,k,k1,max:longint;
    a:array[1..100]of integer;
    b:array[1..5]of char;
    c:array[1..100] of string;
    c1:char;
    s:string;
begin
  readln(i);
  k1:=0;
  max:=0;
  for j:=1 to i do
  begin
  s:='';
  repeat
  read(c1);
  s:=s+c1;
  until c1=' ';
  c[j]:=s;
  read(m,n);
  for i1:=1 to 4 do
  read(b[i1]);
  readln(k);
  if (m>80) and (k>0)then a[J]:=a[j]+8000;
  if (m>85) and (n>80) then a[J]:=a[j]+4000;
  if m>90 then a[j]:=a[j]+2000;
  if (m>85) and (b[4]='Y') then a[j]:=a[j]+1000;
  if (n>80) and (b[2]='Y') then a[j]:=a[j]+850;
  if a[j]>k1 then
  begin
    k1:=a[j];
    i2:=j;
  end;
  max:=max+a[j];
  end;
  writeln(c[i2]);
  writeln(k1);
  writeln(max);
end.
